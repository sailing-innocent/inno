#include <runtime/engine.h>

#include <runtime/core/base/macro.h>
// reflection register
// world manager
#include "runtime/function/global/global_context.h"
// input_system
// particle_manager
// physics_manager
// render_system
#include "runtime/function/render/window_system.h"
// debug_draw

INNO_NAMESPACE_BEGIN

bool g_is_editor_mode {false};
std::unordered_set<std::string> g_editor_tick_component_types {};

void InnoEngine::startEngine(const std::string& config_file_path)
{
    // Reflection
    g_runtime_global_context.startSystems(config_file_path);
    LOG_DEBUG("Engin Start");
}

void InnoEngine::shutdownEngine()
{
    LOG_INFO("Engine Shutdown");
    g_runtime_global_context.shutdownSystems();
    // Reflection
}

void InnoEngine::initalize() {
    LOG_INFO("Engine Initialized");
}
void InnoEngine::clear() {
    LOG_INFO("Engine Clear");
}

void InnoEngine::run()
{
    std::shared_ptr<WindowSystem> window_system = g_runtime_global_context.m_window_system;
    ASSERT(window_system);

    LOG_INFO("Window System Ready, Start Window Loop");
    while (!window_system->shouldClose())
    {
        const float delta_time = calculateDeltaTime();
        tickOneFrame(delta_time);
    }
}

float InnoEngine::calculateDeltaTime() 
{
    float delta_time;
    {
        using namespace std::chrono;

        steady_clock::time_point tick_time_point = steady_clock::now();
        duration<float> time_span = duration_cast<duration<float>>(tick_time_point - m_last_tick_time_point);
        delta_time = time_span.count();
        m_last_tick_time_point = tick_time_point;
    }
    return delta_time;
}

bool InnoEngine::tickOneFrame(float delta_time)
{
    // LOG_INFO("TICKING...");
    // logicTick
    // calculateFPS
    // swap render data
    renderTick(delta_time);
    // debug renderer

    g_runtime_global_context.m_window_system->pollEvents();
    // setTitle

    const bool should_window_close = g_runtime_global_context.m_window_system->shouldClose();
    return !should_window_close;
}

void InnoEngine::logicalTick(float delta_time)
{
    // world_manager->tick
    // input_system->tick
}

bool InnoEngine::renderTick(float delta_time)
{
    // g_runtime_global_context.m_render_system->tick(delta_time);
    return true;
}

int drawHistogram(std::vector<float>& data) {
    if (data.size() == 0) { return -1; }
    auto _min = data[0];
    auto _max = data[0];
    for (auto item: data) {
        if (_min > item) { _min = item; }
        if (_max < item) { _max = item; }
    }
    sail::Histogram2D his(data, _max, _min);
    sail::VisNode vn;
    his.draw(vn);
    std::vector<float> vf;
    std::vector<uint16_t> iu;
    vn.genING(vf, iu);
    std::cout << "iu: ["; 
    for (auto i: iu) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    std::cout << "vf: ["; 
    for (auto i: vf) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;

    ing::CanvasApp app(vertShaderPath, fragShaderPath);

    if (!app.setVertex(vf, vf.size())) {
        std::cout << "Init Vertices Failed~" << std::endl;
    }
    if (!app.setIndex(iu, iu.size())) {
        std::cout << "Init Indices Failed" << std::endl;
    }

    
    try {
        app.init();
        app.run();
        app.terminate();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}


int drawTriangle() {
    sail::point p1(-0.5, 0.0, 0.0, 1.0);
    sail::point p2(0.5, 0.0, 0.0, 1.0);
    sail::point p3(0.0, 0.5, 0.0, 1.0);
    sail::Triangle tri(p1, p2, p3);
    sail::VTriangle vtri;
    tri.visualize(vtri);

    std::vector<float> vf;
    std::vector<uint16_t> iu;
    vtri.genING(vf, iu);

    ing::CanvasApp app(vertShaderPath, fragShaderPath);

    if (!app.setVertex(vf, vf.size())) {
        std::cout << "Init Vertices Failed~" << std::endl;
    }
    if (!app.setIndex(iu, iu.size())) {
        std::cout << "Init Indices Failed" << std::endl;
    }

    
    try {
        app.init();
        app.run();
        app.terminate();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
int drawRect2D() {
    sail::point lb(-0.5f, -0.5f, 0.0f, 1.0f);
    float width = 1.0f;
    float height = 1.0f;
    sail::Rect2D rec(lb, width, height);
    sail::VisNode vn;
    rec.visualize(vn);
    std::vector<float> vf;
    std::vector<uint16_t> iu;
    vn.genING(vf, iu);

    std::cout << "["; 
    for (auto i: iu) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    // iu[5] = 3;
    ing::CanvasApp app(vertShaderPath, fragShaderPath);

    if (!app.setVertex(vf, vf.size())) {
        std::cout << "Init Vertices Failed~" << std::endl;
    }
    if (!app.setIndex(iu, iu.size())) {
        std::cout << "Init Indices Failed" << std::endl;
    }

    
    try {
        app.init();
        app.run();
        app.terminate();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int visualizeDistribution() {
    double _start = -3.0;
    double _end = 3.0;
    int segs = 18;
    double gap = (_end - _start) / segs;
    sail::GaussianDistribution1D gd;
    std::vector<float> data; // = {1.0f, 3.0f, 2.0f, 4.0f, 1.0f};
    for (auto i = 0; i < segs-1; i++) {
        data.push_back(static_cast<float>(gd(_start+i*gap, _start+(i+1)*gap)));
    }    

    int res = drawHistogram(data);
    return res;
}


INNO_NAMESPACE_END