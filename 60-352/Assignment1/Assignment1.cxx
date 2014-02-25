/******************************************************************************
    Written by:   Jeremy High
    Student ID:   103304652
    Written on:   January 29th, 2014

    A simple program that will draw a line as the user tells it to by
    plotting each pixel between the two end points.
******************************************************************************/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

using std::cin;
using std::max;
using std::min;
using std::vector;

struct point {
  int x;
  int y;
};

vector<point> points; 

/********************************************************************
    Uses Bresenham's Algorithm to find every point between two
    end points and saves their coordinates to a vector

    x0  - x coordinate of first end point
    y0  - y coordinate of first end point
    x1  - x coordinate of second end point
    y1  - y coordinate of second end point
********************************************************************/
void bresenhamsAlgorithm(int x0, int y0, int x1, int y1) {
  const int deltaX = x1 - x0, 
            deltaY = y1 - y0, 
            twoDeltaY = 2 * deltaY,
            twoDeltaX = 2 * deltaX,
            twoDeltaYMinusTwoDeltaX = twoDeltaY - twoDeltaX,
            twoDeltaXMinusTwoDeltaY = twoDeltaX - twoDeltaY;

  int xs, 
      ys, 
      xe,
      ye,
      step,
      pk = twoDeltaY - deltaX,
      pk2 = twoDeltaX - deltaY;

  double m = (deltaY / (double)deltaX),
         absM = abs(m);


  /* Picks which point is the start and which is the end */
  if (absM < 1) {
    if (x0 < x1) {
      xs = x0;
      xe = x1;
      ys = y0;
      ye = y1;
    } else if (x0 == x1) {
      xs = x0;
      xe = x1;
      ys = min(y0, y1);
      ye = max(y0, y1);
    } else {
      xs = x1;
      xe = x0;
      ys = y1;
      ye = y0;
    }
  } else {
    if (y0 < y1) {
      ys = y0;
      ye = y1;
      xs = x0;
      xe = x1;
    } else if (y0 == y1) {
      ys = y0;
      ye = y1;
      xs = min(x0, x1);
      xe = max(x0, x1);
    } else {
      ys = y1;
      ye = y0;
      xs = x1;
      xe = x0;
    }
  }

  /* Plots a vertical line */
  if (deltaX == 0) { 
    while (ys <= ye) {
      points.emplace_back(point{xs, ys});
      fprintf(stdout, "Point at (%d, %d)\n", xs, ys);

      ++ys;
    }

  /* Plots a horizontal line */  
  } else if (deltaY == 0) {
    while (xs <= xe) {
      points.emplace_back(point{xs, ys});
      fprintf(stdout, "Point at (%d, %d)\n", xs, ys);

      ++xs;
    }

  /* Absolute value of slope equal to 1 */  
  } else if (absM == 1) {
    if (ys < ye) {
      step = 1;
    } else {
      step = -1;
    }
    while (xs <= xe) {
      points.emplace_back(point{xs, ys});
      fprintf(stdout, "Point at (%d, %d)\n", xs, ys);

      ++xs;
      ys += step;
    }
  
  /* Absolute value of slope greater than 1 */
  } else if (absM > 1) {
      if (m > 0) {
        step = 1;
      } else {
        step = -1;
      }

    fprintf(stderr, "Abs(m): %f, m: %f, xs: %d, xe: %d, ys: %d, ye: %d\n", absM, m, xs, xe, ys, ye);
    while (ys <= ye) {
      points.emplace_back(point{xs, ys});
      fprintf(stdout, "Point %d at (%d, %d)\n", pk, xs, ys);

      ++ys;

      if (pk2 < 0) {
        pk2 += twoDeltaX;
      } else {
        xs += step;
        pk2 += twoDeltaXMinusTwoDeltaY;
      }
    }

  /* Absolute value of slope less than 1 */
  } else if (absM < 1) {
    if (m > 0) {
      step = 1; 
    } else {
      step = -1;
    }

    while (xs <= xe) {
      points.emplace_back(point{xs, ys});
      fprintf(stdout, "Point %d at (%d, %d)\n", pk, xs, ys);

      ++xs;

      if (pk < 0) {
        pk += twoDeltaY;
      } else {
        ys += step;
        pk += twoDeltaYMinusTwoDeltaX;
      }
    }
  }
}

static void errorCallback(int error, const char* description) {
  fprintf(stderr, "%s", description);
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

int main() {
  int x0,
      y0,
      x1,
      y1;

  GLFWwindow* window;

  fprintf(stdout, "Exits on hitting escape.\n
                   Enter the coordinates of your first end point (eg 10 10 = x y): ");
  cin >> x0 >> y0;
  fprintf(stdout, "Enter the coordinates of your second end point (eg 10 10 = x y): ");
  cin >> x1 >> y1;

  glfwSetErrorCallback(errorCallback);

  bresenhamsAlgorithm(x0, y0, x1, y1);

  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(-1);
  }

  window = glfwCreateWindow(1024, 768, "Assignment 1", NULL, NULL);

  if (!window) {
    fprintf(stderr, "Failed to create window\n");
    exit(-1);
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyCallback);

  while (!glfwWindowShouldClose(window)) {
    int width = 1024, 
        height = 768;

    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(width/-2, width/2, height/-2, height/2, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_POINTS);
    for(auto elem : points) {  
      glColor3f(255.f, 255.f, 255.f);         //Sets pixel color to white
      glVertex2i(elem.x, elem.y);             //Plots pixel
    }
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
