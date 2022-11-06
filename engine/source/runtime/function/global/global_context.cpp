#include <runtime/function/global/global_context.h>

namespace inno
{
RuntimeGlobalContext g_runtime_global_context;

void RuntimeGlobalContext::startSystems(const std::string& config_file_path)
{
    // m_config_manager
    // m_file_system
    // m_logger_system
    // m_asset_manager
    // m_physics_manager
    m_world_manager = std::make_shared<WorldManager>();
    // m_world_manager->Initialize();
    // m_window_system
    // m_input_system
    // m_particle_system
    m_render_system = std::make_shared<RenderSystem>();
    // render system init info
    // binding window system
    // init render system

    // m_debugdraw_manager
    // m_render_debug_config
}

void RuntimeGlobalContext::shutdownSystems()
{
    // clear
}

} // namespace inno