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

int cx;
int cy;

static void errorCallback(int error, const char* description) {
  fprintf(stderr, "Error #%d: %s", error, description);
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

static void mouseCallback(GLFWwindow* window, int button, int action, int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
  
  } else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
  
  }
}

static void cursorPosCallback(GLFWwindow* window, double x, double y) {
  cx = int(x);
  cy = int(y);
}

int main() {
  int width = 1024,     //Window size
      height = 768;     //in pixels

  GLFWwindow* window;

  fprintf(stdout, "Exits on hitting escape.\n");

  glfwSetErrorCallback(errorCallback);

  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(-1);
  }

  window = glfwCreateWindow(1024, 768, "Assignment 3", NULL, NULL);

  if (!window) {
    fprintf(stderr, "Failed to create window\n");
    exit(-1);
  }

  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, keyCallback);
  glfwSetMouseButtonCallback(window, mouseCallback);
  glfwSetCursorPosCallback(window, cursorPosCallback);

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

    glBegin(QUADS);
      
    glEnd();


    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
