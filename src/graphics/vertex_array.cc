#include "vertex_array.h"

void VertexArray::AddVertexBuffer(const std::vector<GLfloat>& data) {
    // Bind the vertex array so we can modify it
    this->Bind();

    // Create buffer
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // Add data to the buffer
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);

    // Add vertex positions as an atrribute on the buffer (may make "3" be passed as a function so you can specify the stride)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0);

    // Unbind the vertex array so we don't accidentally modify it later
    this->Unbind();
}

void VertexArray::AddIndexBuffer(const std::vector<GLuint>& data) {
    // Bind the vertex array so we can modify it
    this->Bind();

    // Create buffer
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);

    // Add data to the buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GLuint), data.data(), GL_STATIC_DRAW);

    /* Because the indices are already on the buffer because they were both bound at the same time, we don't need to manually add the attribute */

    // Store the total indices in the vertex array
    m_indices = data.size();

    // Unbind the vertex array so we don't accidentally modify it later
    this->Unbind();
}

void VertexArray::Draw() {
    // This just binds the vertex array so the next function, "glDrawElements" can draw the data, then unbinds it
    this->Bind();
    glDrawElements(GL_TRIANGLES, m_indices, GL_UNSIGNED_INT, 0);
    this->Unbind();
}
