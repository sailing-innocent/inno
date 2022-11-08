#pragma once

#include <array>
#include <memory>
#include <optional>

#include <common.h>

INNO_NAMESPACE_BEGIN

class WindowSystem;
class RHI;
class RenderResourceBase;
class RenderPipelineBase;
class RenderScene;
class RenderCamera;
class WindowUI;
class DebugDrawManager;

struct RenderSystemInitInfo
{
    std::shared_ptr<WindowSystem> window_system;
    std::shared_ptr<DebugDrawManager> debugdraw_manager;
};

struct EngineContentViewport
{
    float x { 0.0f };
    float y { 0.0f };
    float width { 0.0f };
    float height { 0.0f }; 
};

class RenderSystem
{
public:
    RenderSystem() = default;
    ~RenderSystem();

    void initialize(RenderSystemInitInfo init_info);
    void tick(float delta_time);
    void clear();

    
private:
};



INNO_NAMESPACE_END
