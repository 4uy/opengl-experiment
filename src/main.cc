#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/window.h"
#include "core/time.h"

int main() {
    std::cout << "Hello, world!" << std::endl;

    Window window(1280, 720, "Minecraft");
    GLFWwindow* native_window = window.Get();

    Time time;

    glViewport(0, 0, window.GetWidth(), window.GetHeight());
    glClearColor(0.1f, 0.1f, 0.2f, 0.0f);

    while (!glfwWindowShouldClose(native_window)) {
        time.Update();

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(native_window);
        glfwPollEvents();
    }

    return 0;
}
