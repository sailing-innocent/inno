#include "ing_draw_manager.h"
#include "runtime/function/global/global_context.h"
#include "runtime/function/render/render_system.h"
// math

INNO_NAMESPACE_BEGIN

// initialize
// get app -> setupPipeline
void IngDrawManager::initialize() {
    m_app = g_runtime_global_context.m_render_system->getApp();
    setupPipelines();
}

void IngDrawManager::setupPipelines()
{
    for (uint8_t i = 0; i < IngDrawPipelineType::_ing_draw_pipeline_type_count; i++)
    {
        m_ing_draw_pipeline[i] = new IngDrawPipeline((IngDrawPipelineType)i);
        m_ing_draw_pipeline[i]->initialize();
    }
    // Allocator
    // font
}

void IngDrawManager::destroy()
{
    for (uint8_t i = 0; i < IngDrawPipelineType::_ing_draw_pipeline_type_count; i++)
    {
        m_ing_draw_pipeline[i]->destory();
        delete m_ing_draw_pipeline[i];
    }
    // allocator->destroy()
    // del allocator
    // del m_font
}

void IngDrawManager::clear()
{
    std::lock_guard<std::mutex> guard(m_mutex);
    // context clear
}

void IngDrawManager::tick(float delta_time)
{
    std::lock_guard<std::mutex> guard(m_mutex);
    m_app->tick(delta_time);
    // not update when ticking
    // allocator->tick() update parameter
    // m_ing_draw_context->tick() // remove dead primitives
}

void IngDrawManager::preparePassData(std::shared_ptr<RenderResourceBase> render_resource)
{
    // const RenderResource* resource = get()
    // m_proj_view_matrix = resource->m_mesh_perframe_storage_buffer_object.pvm
}

INNO_NAMESPACE_END
