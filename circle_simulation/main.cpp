#include <GLFW/glfw3.h>

#include <cmath>
#include <iostream>

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

constexpr float WINDOW_LEFT = 0.0f;
constexpr float WINDOW_RIGHT = WINDOW_WIDTH;
constexpr float WINDOW_TOP = 0.0f;
constexpr float WINDOW_BOTTOM = WINDOW_HEIGHT;

const int NUM_SEGMENTS = 100;

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    // Center of the circle
    glVertex2f(cx, cy);
    for (int i = 0; i <= NUM_SEGMENTS; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(NUM_SEGMENTS);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

int main(void) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Circle Simulation", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(WINDOW_LEFT, WINDOW_RIGHT, WINDOW_BOTTOM, WINDOW_TOP, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(1.0f, 0.0f, 0.0f);
        drawCircle(320.0f, 240.0f, 5.0f);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
