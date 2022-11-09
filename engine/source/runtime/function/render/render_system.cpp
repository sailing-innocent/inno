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

// vulkan_rhi

INNO_NAMESPACE_BEGIN

RenderSystem::~RenderSystem() {
    clear();
}

void RenderSystem::initialize(RenderSystemInitInfo init_info) 
{
    // config manager
    // asset manager
    
    // render context initalize
    // m_rhi -> initialize

    // global rendering resource

    // setup render camera

    // setup render scene

    // initialize render pipeline

    // descriptor layout
    LOG_INFO("Init Render System");
}

void RenderSystem::tick(float delta_time)
{
    // process swap data
    // rhi prepare context
    // render_resource update per frame buffer
    // render_scene update visible objects
    // prepare pass data
    // debug manager -> tick

    // render one frame 
    // switch (m_render_pipeline_type)
}

void RenderSystem::processSwapData()
{
    // update game object if needed
}

void RenderSystem::clear() {
    LOG_INFO("Clear Render System");
}

INNO_NAMESPACE_END
