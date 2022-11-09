#include "runtime/function/render/render_system.h"

#include "runtime/core/base/macro.h"

// asset_manager
// config_manager
// render_camera
// render_pass
// render_pipeline
// render_resource
// render_scene
// window_system
// global_context
// debug_draw_manager
// main_camera_pass
// particle_pass

#include "runtime/function/render/interface/vulkan/vulkan_rhi.h"

INNO_NAMESPACE_BEGIN

RenderSystem::~RenderSystem() {
    clear();
}

void RenderSystem::initialize(RenderSystemInitInfo init_info) 
{
    // config manager
    // asset manager
    
    // render context initalize
    RHIInitInfo rhi_init_info;
    rhi_init_info.window_system = init_info.window_system;
    m_rhi = std::make_shared<VulkanRHI>();
    m_rhi->initialize(rhi_init_info);

    // global rendering resource

    // setup render camera

    // setup render scene

    // initialize render pipeline

    // descriptor layout
    LOG_INFO("Init Render System");
}

void RenderSystem::tick(float delta_time)
{
    // LOG_INFO("Render System Ticking...");
    // process swap data
    // m_rhi->prepareContext();
    
    // render_resource update per frame buffer
    // render_scene update visible objects
    // prepare pass data
    // g_runtime_global_context.m_debugdraw_manager->tick(delta_time);


    // render one frame 
    // switch (m_render_pipeline_type)
}

void RenderSystem::processSwapData()
{
    // update game object if needed
}

void RenderSystem::clear() {
    LOG_INFO("Clear Render System");
    if (m_rhi)
    {
        m_rhi->clear();
    }
}

std::shared_ptr<RHI> RenderSystem::getRHI() const { return m_rhi; }

INNO_NAMESPACE_END
