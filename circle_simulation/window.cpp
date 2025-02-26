#include "circle_simulation/window.hpp"

#include <GLFW/glfw3.h>

#include <stdexcept>

Window::Window(int width, int height, const std::string& title) {
    if (glfwInit() == 0) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    window_ = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (window_ == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window_);
}

Window::~Window() {
    if (window_ != nullptr) {
        glfwDestroyWindow(window_);
    }
    glfwTerminate();
}

bool Window::shouldClose() const { return glfwWindowShouldClose(window_) != 0; }

void Window::swapBuffers() const { glfwSwapBuffers(window_); }

void Window::pollEvents() { glfwPollEvents(); }

void Window::clear() { glClear(GL_COLOR_BUFFER_BIT); }
