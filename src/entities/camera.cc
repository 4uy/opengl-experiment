#include "camera.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(Window& window) : m_window(window) {
    // ...
}

// This is an AWFUL input system, it is completely temporary until I create the event system.
void Camera::HandleInput() {
    GLFWwindow* window = m_window.Get();

    // W key
    if (glfwGetKey(window, GLFW_KEY_W)) {
        position.x += -glm::cos(glm::radians(rotation.y + 90)) * speed;
        position.z += -glm::sin(glm::radians(rotation.y + 90)) * speed;
    }

    // S key
    if (glfwGetKey(window, GLFW_KEY_S)) {
        position.x += glm::cos(glm::radians(rotation.y + 90)) * speed;
        position.z += glm::sin(glm::radians(rotation.y + 90)) * speed;
    }

    // A key
    if (glfwGetKey(window, GLFW_KEY_A)) {
        position.x += -glm::cos(glm::radians(rotation.y)) * speed;
        position.z += -glm::sin(glm::radians(rotation.y)) * speed;
    }

    // D key
    if (glfwGetKey(window, GLFW_KEY_D)) {
        position.x += glm::cos(glm::radians(rotation.y)) * speed;
        position.z += glm::sin(glm::radians(rotation.y)) * speed;
    }

    // Left arrow key
    if (glfwGetKey(window, GLFW_KEY_LEFT)) {
        rotation.y -= sensitivity;
    }

    // Right arrow key
    if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
        rotation.y += sensitivity;
    }

    // Up arrow key
    if (glfwGetKey(window, GLFW_KEY_UP)) {
        rotation.x -= sensitivity;
    }

    // Down arrow key
    if (glfwGetKey(window, GLFW_KEY_DOWN)) {
        rotation.x += sensitivity;
    }

    // Space key
    if (glfwGetKey(window, GLFW_KEY_SPACE)) {
        position.y += speed;
    }

    // Shift key
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) {
        position.y -= speed;
    }
}

glm::mat4 Camera::GetViewMatrix() {
    glm::mat4 matrix(1.0f);

    matrix = glm::rotate(matrix, glm::radians(rotation.x), {1, 0, 0});
    matrix = glm::rotate(matrix, glm::radians(rotation.y), {0, 1, 0});
    matrix = glm::rotate(matrix, glm::radians(rotation.z), {0, 0, 1});
    matrix = glm::translate(matrix, -position);

    return matrix;
}

glm::mat4 Camera::GetProjectionMatrix() {
    glm::mat4 matrix;

    float width = m_window.GetWidth();
    float height = m_window.GetHeight();

    matrix = glm::perspective(glm::radians(m_fov), width / height, m_near, m_far);

    return matrix;
}
