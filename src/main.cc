#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/window.h"

int main() {
    std::cout << "Hello, world!" << std::endl;

    Window window(1280, 720, "Minecraft");
    GLFWwindow* native_window = window.Get();

    while (!glfwWindowShouldClose(native_window)) {
        glfwSwapBuffers(native_window);
        glfwPollEvents();
    }

    return 0;
}
