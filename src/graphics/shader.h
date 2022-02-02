#pragma once

#include <string>

#include <glad/glad.h>

class Shader {
public:
    Shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path);
public:
    void Bind() { glUseProgram(m_program); }
    void Unbind() { glUseProgram(0); }
public:
    void LoadUniform(const std::string& uniform, int value) { Bind(); glUniform1i(glGetUniformLocation(m_program, uniform.c_str()), value); Unbind(); }
    void LoadUniform(const std::string& uniform, float value) { Bind(); glUniform1f(glGetUniformLocation(m_program, uniform.c_str()), value); Unbind(); }
private:
    GLuint Compile(GLenum shader_type, const std::string& shader_source);
private:
    GLuint m_program;
    GLuint m_vs;
    GLuint m_fs;
};
