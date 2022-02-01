#include "time.h"

#include <GLFW/glfw3.h>

Time::Time() {
    last_frame = glfwGetTime();
}

void Time::Update() {
    // Get current time
    float now = glfwGetTime();

    // Find delta time (time since last frame)
    delta_time = now - last_frame;

    // Set the time for the next frame
    last_frame = glfwGetTime();
}
