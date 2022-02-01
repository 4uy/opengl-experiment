#pragma once

#include <vector>

#include <glad/glad.h>

class VertexArray {
public:
    VertexArray() { glGenVertexArrays(1, &m_id); }
    ~VertexArray() { glDeleteVertexArrays(1, &m_id); }
public:
    void Bind() { glBindVertexArray(m_id); }
    void Unbind() { glBindVertexArray(0); }
public:
    void AddVertexBuffer(const std::vector<GLfloat>& data);
    void AddIndexBuffer(const std::vector<GLuint>& data);
public:
    void Draw();
private:
    GLuint m_id;
    GLsizei m_indices;
};
