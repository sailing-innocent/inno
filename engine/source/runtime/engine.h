#pragma once
#ifndef INNO_ENGINE_H_
#define INNO_ENGINE_H_
#include <string>
#include <vector>
#include <iostream>
#include <sail/math.h>
#include <sail/ui/figure.h>
#include <ing/app/vk_canvas.hpp>

namespace inno
{

const std::string vertShaderPath = "E:/assets/shaders/canvas/vert.spv";
const std::string fragShaderPath = "E:/assets/shaders/canvas/frag.spv";
int drawRect2D();
int drawTriangle();
int drawHistogram(std::vector<float>& data);
int visualizeDistribution();

class InnoEngine
{
    // friend class InnoEditor;
    // static const float s_fps_alpha;
public:
    // void config(const std::string& config_file_path);
    // void init();
    // bool isQuit() const { return m_is_quit;}
    // void clear();
    // void shutdown();
protected:
    bool m_is_quit {false};
    int m_frame_count {0};
    int m_fps {0};
};


} // inno

#endif // INNO_ENGINE_H_