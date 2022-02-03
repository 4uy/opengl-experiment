#pragma once

#include <glm/vec3.hpp>
#include <glm/matrix.hpp>

#include "../core/window.h"

class Camera {
public:
    Camera(Window& window);
public:
    void HandleInput();
public:
    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
public:
    glm::vec3 position;
    glm::vec3 rotation;
    float speed = 0.1f;
    float sensitivity = 2.0f;
private:
    Window m_window;
    float m_fov = 60.0f;
    float m_near = 0.1f;
    float m_far = 100.0f;
};
