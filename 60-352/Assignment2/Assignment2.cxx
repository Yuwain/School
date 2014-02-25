/******************************************************************************
    Written by:   Jeremy High
    Student ID:   103306452
    Written on:   February 12th, 2014

    This program moves around a truck with the arrow keys. The up and down
    keys change the speed of the truck and the left and right keys move
    the truck in that direction
******************************************************************************/
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

int speed = 2;
double angle = speed;

/* Truck body defaults */
int x1 = -256;
int y1 = 202;
int x2 = 256;
int y2 = 10;

/* Truck taxi defaults */
int tx1 = 260; 
int ty1 = 202;
int tx2 = 390;
int ty2 = 10;

/* Wheel 1 defaults */
int w1x1 = -148;
int w1y1 = 30;
int w1x2 = -108;
int w1y2 = -10;

/* Wheel 2 defaults */
int w2x1 = 108;
int w2y1 = 30;
int w2x2 = 148;
int w2y2 = -10;

static void errorCallback(int error, const char* description) {
  fprintf(stderr, "Error #%d: %s", error, description);
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
  if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
    if (speed >= 0) {
      ++speed;
    }
  }
  if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
    if (speed != 0) {
      --speed;
    }
  }
  if (key == GLFW_KEY_RIGHT && (action == GLFW_REPEAT || action == GLFW_PRESS)) {
    /* Move truck right */
    x1 += speed;
    x2 += speed;
    w1x1 += speed;
    w1x2 += speed;
    w2x1 += speed;
    w2x2 += speed;
    tx1 += speed;
    tx2 += speed;

    angle -= (speed/2);
  }
  if (key == GLFW_KEY_LEFT && (action == GLFW_REPEAT || action == GLFW_PRESS)) {
    /* Move truck left*/
    x1 -= speed;
    x2 -= speed;
    w1x1 -= speed;
    w1x2 -= speed;
    w2x1 -= speed;
    w2x2 -= speed;
    tx1 -= speed;
    tx2 -= speed;
    
    angle += (speed/2);
  }
}

int main() {
  int width = 1024,     //Window size
      height = 768;     //in pixels

  GLFWwindow* window;

  fprintf(stdout, "Exits on hitting escape.\n"
                  "Up and down arrows change the speed, left and right move the truck\n");

  glfwSetErrorCallback(errorCallback);

  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(-1);
  }

  window = glfwCreateWindow(1024, 768, "Assignment 2", NULL, NULL);

  if (!window) {
    fprintf(stderr, "Failed to create window\n");
    exit(-1);
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyCallback);

  while (!glfwWindowShouldClose(window)) {
    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(width/-2, width/2, height/-2, height/2, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Draw truck body */
    glBegin(GL_QUADS);
     glColor3f(0.f, 255.f, 0.f);  //Body is green
     glVertex2i(x1, y1);
     glVertex2i(x2, y1);
     glVertex2i(x2, y2);
     glVertex2i(x1, y2);

     glVertex2i(tx1, ty1);
     glVertex2i(tx2, ((ty1+ty2)/2));
     glVertex2i(tx2, ty2);
     glVertex2i(tx1, ty2);
    glEnd();

    /* Rotate and draw wheel 1 */
    glPushMatrix();
     glTranslatef((w1x1 + 20), (w1y1 - 20), 0);
     glRotatef(angle, 0, 0, 1);
     glTranslatef((0 - (w1x1 + 20)), (0 - (w1y1 - 20)), 0);

     glColor3f(255, 0, 255);    //Wheels are purple
     glRectd(w1x1, w1y1, w1x2, w1y2);
    glPopMatrix();

    /* Rotate and draw wheel 2 */
    glPushMatrix();
     glTranslatef((w2x1 + 20), (w2y1 - 20), 0);
     glRotatef(angle, 0, 0, 1);
     glTranslatef((0 - (w2x1 + 20)), (0 - (w2y1 - 20)), 0);
     
     glColor3f(255, 0, 255);    //Wheels are purple
     glRectd(w2x1, w2y1, w2x2, w2y2);
    glPopMatrix();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
