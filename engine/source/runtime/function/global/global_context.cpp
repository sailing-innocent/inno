#include <runtime/function/global/global_context.h>
#include "runtime/core/log/log_system.h"

#include "runtime/function/render/window_system.h"
#include "runtime/function/render/render_system.h"

INNO_NAMESPACE_BEGIN

RuntimeGlobalContext g_runtime_global_context;

void RuntimeGlobalContext::startSystems(const std::string& config_file_path)
{
    // m_config_manager
    // m_file_system
    m_logger_system = std::make_shared<LogSystem>();
    // m_asset_manager
    // m_physics_manager
    // m_world_manager = std::make_shared<WorldManager>();
    // m_world_manager->Initialize();
    m_window_system = std::make_shared<WindowSystem>();
    WindowCreateInfo window_create_info;
    m_window_system->initialize(window_create_info);
    // m_input_system
    // m_particle_system
    m_render_system = std::make_shared<RenderSystem>();
    RenderSystemInitInfo render_init_info;
    render_init_info.window_system = m_window_system;
    m_render_system->initialize(render_init_info);

    // m_debugdraw_manager
    // m_render_debug_config
}

void RuntimeGlobalContext::shutdownSystems()
{
    m_render_system->clear();
    m_render_system.reset();
    m_window_system.reset();
    m_logger_system.reset();
}

INNO_NAMESPACE_END