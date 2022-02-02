#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(Window& window) : m_window(window) {
    // ...
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
