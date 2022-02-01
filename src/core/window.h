#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, std::string title);
    ~Window();
public:
    GLFWwindow* Get() { return m_window; }
private:
    GLFWwindow* m_window;
    int m_width, m_height;
    std::string m_title;
};
