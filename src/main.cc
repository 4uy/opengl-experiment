#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "core/window.h"
#include "core/time.h"
#include "graphics/vertex_array.h"
#include "graphics/primitives.h"
#include "graphics/shader.h"
#include "entities/camera.h"

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
    glEnable(GL_DEPTH_TEST);

    // Create shape
    VertexArray vertex_array = primitives::Cube();
    
    // Create screen shader
    Shader shader(
        "res/shaders/basic.glsl",
        "res/shaders/fragment.glsl"
    );

    // Create matrices
    glm::mat4 model(1.0f);
    glm::mat4 view(1.0f);
    glm::mat4 projection(1.0f);

    // Create camera
    Camera camera(window);
    camera.position.z = 3.0f;

    // Move shape to world center
    model = glm::translate(model, glm::vec3(-0.5f, -0.5f, -0.5f));

    // Game loop
    while (!glfwWindowShouldClose(native_window)) {
        // Update time
        time.Update();

        // OpenGL stuff
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update camera
        view = camera.GetViewMatrix();
        projection = camera.GetProjectionMatrix();

        // Upload matrices to shader
        shader.LoadUniform("u_model", model);
        shader.LoadUniform("u_view", view);
        shader.LoadUniform("u_projection", projection);

        // Draw shape
        shader.Bind();
        vertex_array.Draw();
        shader.Unbind();
                
        // Update window
        window.Update();
    }

    return 0;
}
