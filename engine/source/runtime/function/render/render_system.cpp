
#include "runtime/function/render/render_system.h"

#include "runtime/core/base/macro.h"

#include "runtime/function/render/window_system.h"

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
#include "runtime/function/render/ingdraw/ing_draw_manager.h"
// main_camera_pass
// particle_pass

// #include "runtime/function/render/interface/vulkan/vulkan_rhi.h"

INNO_NAMESPACE_BEGIN

RenderSystem::~RenderSystem() {
    clear();
}


bool genIndex(std::vector<uint16_t>& vu) {
    const size_t size = 6;
    vu.resize(size);
    uint16_t indi[size] = {
        0, 1, 2, 2, 3, 0
    };
    for (auto i = 0; i < size; i++) {
        vu[i] = indi[i];
    }
    return true;
}

bool genVertex(std::vector<float>& vf) {
    vf =  {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f
    };
    return true;
}

void RenderSystem::initialize(RenderSystemInitInfo init_info) 
{
    // config manager
    // asset manager
    
    // render context initalize
    // RHIInitInfo rhi_init_info;
    // rhi_init_info.window_system = init_info.window_system;
    // m_rhi = std::make_shared<VulkanRHI>();
    // m_rhi->initialize(rhi_init_info);

    std::vector<float> vertices;
    genVertex(vertices);

    std::vector<uint16_t> indices;
    genIndex(indices);

    m_app = std::make_shared<ing::CanvasApp>();
    if (!m_app->setVertex(vertices, vertices.size())) {
        LOG_FATAL("init verttices failed");
    }
    if (!m_app->setIndex(indices, indices.size())) {
        LOG_FATAL("init indices failed");
    }
    m_app->init(init_info.window_system->getWindow());

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

    g_runtime_global_context.m_ing_draw_manager->tick(delta_time);
    // m_app->tick(delta_time);

    // render one frame 
    // switch (m_render_pipeline_type)
    // m_render_pipeline->forward render
    m_app->tick(delta_time);
}

void RenderSystem::processSwapData()
{
    // update game object if needed
}

void RenderSystem::clear() {
    LOG_INFO("Clear Render System");
    /*
    if (m_rhi)
    {
        m_rhi->clear();
    }
    */
    if (m_app) {
        m_app->wait();
        m_app->terminate();
    }
}

std::shared_ptr<ing::CanvasApp> RenderSystem::getApp() const { return m_app; }

// std::shared_ptr<RHI> RenderSystem::getRHI() const { return m_rhi; }

INNO_NAMESPACE_END
