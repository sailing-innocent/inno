#pragma once
#ifndef INNO_ENGINE_H_
#define INNO_ENGINE_H_
#include <string>
#include <vector>
#include <iostream>
#include <sail/math.h>
#include <sail/ui/figure.h>
#include <ing/app/vk_canvas.hpp>

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

#include <atomic>
#include <chrono>
#include <filesystem>
#include <string>
#include <unordered_set>

#include <common.h>

INNO_NAMESPACE_BEGIN

const std::string vertShaderPath = "E:/assets/shaders/canvas/vert.spv";
const std::string fragShaderPath = "E:/assets/shaders/canvas/frag.spv";
int drawRect2D();
int drawTriangle();
int drawHistogram(std::vector<float>& data);
int visualizeDistribution();

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double _min, double _max) {
    return _min + (_max - _min) * random_double();
}

inline double clamp(double x, double _min, double _max) {
    if (x < _min) { return _min; }
    if (x > _max) { return _max; }
    return x;
}

class InnoEngine
{
    friend class InnoEditor;
    // static const float s_fps_alpha;
public:
    void startEngine(const std::string& config_file_path);
    
    void initalize();
    void clear();
    bool isQuit() const { return m_is_quit; }
    
    void run();
    bool tickOneFrame(float delta_time);
    int getFPS() const { return m_fps; }

    void shutdownEngine();

protected: 
    void logicalTick(float delta_time);
    bool renderTick(float delta_time);
    // void calculateFPS(float delta_time);

    /**
     * Each Frame can only be called once
    */
    float calculateDeltaTime();
protected:
    bool m_is_quit {false};

    std::chrono::steady_clock::time_point m_last_tick_time_point {std::chrono::steady_clock::now()};

    float m_average_duration {0.f};
    int m_frame_count {0};
    int m_fps {0};
};


INNO_NAMESPACE_END

#endif // INNO_ENGINE_H_