#pragma once

#include <GLFW/glfw3.h>

#include <string>

class Window {
   public:
    Window(int width, int height, const std::string& title);

    ~Window();

    [[nodiscard]] bool shouldClose() const;

    void swapBuffers() const;

    static void pollEvents();

    static void clear();

   private:
    GLFWwindow* window_;
};
