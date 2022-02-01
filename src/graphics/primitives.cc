#include "primitives.h"

#include <vector>

#include <glad/glad.h>

VertexArray primitives::Quad() {
    const std::vector<GLfloat> vertices = {
        0.0f,   0.0f,   0.0f,
        1.0f,   0.0f,   0.0f,
        1.0f,   1.0f,   0.0f,
        0.0f,   1.0f,   0.0f
    };
    const std::vector<GLuint> indices = {
        0, 1, 2,
        2, 3, 0
    };

    VertexArray vertex_array;
    vertex_array.AddVertexBuffer(vertices);
    vertex_array.AddIndexBuffer(indices);
    return vertex_array;
}

VertexArray primitives::Cube() {
    const std::vector<GLfloat> vertices = {
        0.0f,   0.0f,   1.0f,
        1.0f,   0.0f,   1.0f,
        0.0f,   1.0f,   1.0f,
        1.0f,   1.0f,   1.0f,
        0.0f,   0.0f,   0.0f,
        1.0f,   0.0f,   0.0f,
        0.0f,   1.0f,   0.0f,
        1.0f,   1.0f,   0.0f 
    };
    const std::vector<GLuint> indices = {
        2, 6, 7,
        2, 3, 7,

        0, 4, 5,
        0, 1, 5,

        0, 2, 6,
        0, 4, 6,

        1, 3, 7,
        1, 5, 7,

        0, 2, 3,
        0, 1, 3,

        4, 6, 7,
        4, 5, 7
    };

    VertexArray vertex_array;
    vertex_array.AddVertexBuffer(vertices);
    vertex_array.AddIndexBuffer(indices);
    return vertex_array;
}
