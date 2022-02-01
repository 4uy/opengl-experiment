#pragma once

class Time {
public:
    Time();
public:
    void Update();
public:
    float delta_time;
private:
    float last_frame;
};
