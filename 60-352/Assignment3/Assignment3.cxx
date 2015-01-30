/******************************************************************************
    Written by:   Jeremy High
    Student ID:   103306452
    Written on:   February 26th, 2014

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
using std::cout;
using std::endl;
using std::vector;

int prey_speed = 2;
int pred_speed = 4;
int spawn_count = 0;

double cx = 0;
double cy = 0;

bool escape = false;

void spawnPrey(int x, int y) {
  cout << "Prey spawned at (" << x << ", " << y << ")" << endl;
}

void spawnPred(int x, int y) {
  cout << "Predator spawned at (" << x << ", " << y << ")" << endl;
}

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
    switch (spawn_count) {
      case 0: spawnPrey(int(cx), int(cy));
              ++spawn_count;
              break;
      case 1: spawnPred(int(cx), int(cy));
              ++spawn_count;
              break;
    }
  }
}

static void cursorPosCallback(GLFWwindow* window, double x, double y) {
  cx = x;
  cy = y;
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

    /* Draw inner box */
    glBegin(GL_LINE_LOOP);
      glVertex2i(-312, 184);
      glVertex2i(-312, -184);
      glVertex2i(312, -184);
      glVertex2i(312, 184);
    glEnd();

    /* Draw outer box */
    glBegin(GL_LINE_LOOP);
      glVertex2i(-412, 284);
      glVertex2i(-412, -284);
      glVertex2i(412, -284);
      glVertex2i(412, -50);
      glVertex2i(512, -50);
      glVertex2i(512, 50);
      glVertex2i(412, 50);
      glVertex2i(412, 284);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
