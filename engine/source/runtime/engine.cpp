#include <runtime/engine.h>

#include <runtime/core/base/macro.h>
// reflection register
// world manager
#include "runtime/function/global/global_context.h"
// input_system
// particle_manager
// physics_manager
#include "runtime/function/render/window_system.h"
#include "runtime/function/render/render_system.h"
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
    g_runtime_global_context.m_render_system->tick(delta_time);
    return true;
}

INNO_NAMESPACE_END