#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/window.h"
#include "core/time.h"
#include "graphics/vertex_array.h"
#include "graphics/primitives.h"

int main() {
    std::cout << "Hello, world!" << std::endl;

    // Initialize GLFW & create a window
    Window window(1280, 720, "Minecraft");
    GLFWwindow* native_window = window.Get();

    // Start tracking some time stats
    Time time;

    // Pre-loop OpenGL stuff
    glViewport(0, 0, window.GetWidth(), window.GetHeight());
    glClearColor(0.1f, 0.1f, 0.2f, 0.0f);

    // Create shape
    VertexArray vertex_array = primitives::Quad();

    // Game loop
    while (!glfwWindowShouldClose(native_window)) {
        // Update time
        time.Update();

        // OpenGL stuff
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw shape
        vertex_array.Draw();

        // Update window
        window.Update();
    }

    return 0;
}
