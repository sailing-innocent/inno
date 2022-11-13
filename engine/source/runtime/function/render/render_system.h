#pragma once

// render entity
// render_guid_allocator
// render_swap_context
// render_type

#include <array>
#include <memory>
#include <optional>
#include <common.h>


// -------------ING--------------
// #include <ing/app/vk_hello.hpp>
#include <ing/app/vk_canvas.hpp>
// ------------------------------

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
    bool testTick(int i);
    void clear();

    std::shared_ptr<ing::CanvasApp> getApp() const;

    // swapLogicRenderData
    // getSwapContext
    // getRenderCamera
    // std::shared_ptr<RHI> getRHI() const;

    // setRenderPipelineType
    // initializeUIRenderBackend
    // updateEngineContentViewport
    // getGuidofPickedMesh
    // getGObjectIDByMeshID
    // getEngineContentViewport
    
    // createAxis
    // setVisibleAxis
    // setSelectedAxis
    // getGOInstanceIdAllocator
    // getGMeshAssetIdAllocator

    // clearForLevelReloading
    
private:
    // m_render_pipeline_type
    // m_swap_context
    // std::shared_ptr<RHI> m_rhi;
    std::shared_ptr<ing::CanvasApp> m_app;
    // m_render_camera
    // m_render_scene
    // m_render_resource
    // m_render_pipeline
    
    void processSwapData();
};

INNO_NAMESPACE_END
