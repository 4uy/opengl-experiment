#include "shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path) {
    // Load shaders
    std::string vertex_shader, fragment_shader;
    std::ifstream vertex_file, fragment_file;

    vertex_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fragment_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        vertex_file.open(vertex_shader_path);
        fragment_file.open(fragment_shader_path);
        std::stringstream vertex_stream, fragment_stream;

        vertex_stream << vertex_file.rdbuf();
        fragment_stream << fragment_file.rdbuf();		

        vertex_file.close();
        fragment_file.close();

        vertex_shader = vertex_stream.str();
        fragment_shader = fragment_stream.str();		
    }

    catch (std::ifstream::failure& e) { std::cout << "Failed to read shader file: " << e.what() << std::endl; }

    // Compile shaders
    m_vs = Compile(GL_VERTEX_SHADER, vertex_shader);
    m_fs = Compile(GL_FRAGMENT_SHADER, fragment_shader);

    // Link shaders
    m_program = glCreateProgram();
    glAttachShader(m_program, m_vs);
    glAttachShader(m_program, m_fs);
    glLinkProgram(m_program);

    GLint success;
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);
    if (!success) {
        GLchar log[512];
        glGetProgramInfoLog(m_program, 512, nullptr, log);
        std::cout << "Failed to link program:\n" << log << std::endl;
    }
}

GLuint Shader::Compile(GLenum shader_type, const std::string& shader_source) {
    GLuint shader = glCreateShader(shader_type);
    const GLchar* source = shader_source.c_str();

    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cout << "Failed to compile shader:\n" << log << std::endl;
    }

    return shader;
}
