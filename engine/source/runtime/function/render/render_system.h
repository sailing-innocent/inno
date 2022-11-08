#pragma once

// render entity
// render_guid_allocator
// render_swap_context
// render_type

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

    // swapLogicRenderData
    // getSwapContext
    // getRenderCamera
    // getRHI

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
    // m_rhi
    // m_render_camera
    // m_render_scene
    // m_render_resource
    // m_render_pipeline
    
    void processSwapData();
};

INNO_NAMESPACE_END