#pragma once

#include <memory>
#include <string>
#include <common.h>

INNO_NAMESPACE_BEGIN

class LogSystem;
// class InputSystem;
// class PhysicsManager
// class FileSystem
// class AssetManager
// class ConfigManager
// class WorldManager;
class RenderSystem;
class WindowSystem;
// class ParticleManager;
// class DebugDrawManager;
// class RenderDebugConfig;

// struct EngineInitParams;


class RuntimeGlobalContext
{
public:
    // create all global systems and initialization these systems
    void startSystems(const std::string& config_file_path);
    // destroy all global systems
    void shutdownSystems();

public:
    std::shared_ptr<LogSystem> m_logger_system;
    // std::shared_ptr<WorldManager> m_world_manager;
    std::shared_ptr<RenderSystem> m_render_system;
    std::shared_ptr<WindowSystem> m_window_system;
};

extern RuntimeGlobalContext g_runtime_global_context;

INNO_NAMESPACE_END