cmake_minimum_required(VERSION 3.20)

# Set project name
project(minecraft)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Glob source files and compile them
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cc" "src/*/*.cc")
add_executable(${PROJECT_NAME} ${SOURCES})

# res/ -> build/
add_custom_command(
    TARGET ${PROJECT_NAME} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Glad
add_subdirectory(lib/glad)
target_include_directories(${PROJECT_NAME} PUBLIC lib/glad/include)
target_link_libraries(${PROJECT_NAME} glad)

# GLFW
add_subdirectory(lib/glfw)
target_include_directories(${PROJECT_NAME} PUBLIC lib/glfw/include)
target_link_libraries(${PROJECT_NAME} glfw)
