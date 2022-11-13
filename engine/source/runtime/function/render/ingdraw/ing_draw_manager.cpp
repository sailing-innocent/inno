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
    // Only to clear cache
    std::lock_guard<std::mutex> guard(m_mutex);
    // not update when ticking
    // allocator->tick() update parameter
    // m_ing_draw_context->tick() // remove dead primitives
}

// draw

void IngDrawManager::preparePassData(std::shared_ptr<RenderResourceBase> render_resource)
{
    // const RenderResource* resource = get()
    // m_proj_view_matrix = resource->m_mesh_perframe_storage_buffer_object.pvm
}

void IngDrawManager::draw(uint32_t current_swapchain_image_index)
{
    static uint32_t once = 1;
    // swapDataToRender
    once = 0;

    // pullEvent(getCurrentCommandBuffer(), "DebugDrawManager", color)
    // Encrypt all the draw method into an event

    // cmdSetViewportPFN() 
    // cmdSetScissorPFN()

    drawIngObject(current_swapchain_image_index);

    // popEvent();
}

void IngDrawManager::prepareDrawBuffer(uint32_t current_swapchain_image_index)
{

}

void IngDrawManager::drawPointLineTriangleBox(uint32_t current_swapchain_image_index)
{
    // m_app->tick(); // require more explicit interface
    // vertex_buffers = m_buffer_allocator->getVertexBuffer()

    // bindVertexBuffer(--CommandBuffer--, 0, 1, vertex_buffers)

    // ??????????????? Seems not binding index, are there any questions?

    std::vector<IngDrawPipeline*> vc_pipelines{
        m_ing_draw_pipeline[IngDrawPipelineType::_ing_draw_pipeline_type_point],
        m_ing_draw_pipeline[IngDrawPipelineType::_ing_draw_pipeline_type_line],
        m_ing_draw_pipeline[IngDrawPipelineType::_ing_draw_pipeline_type_triangle]
    };

    // vc_start_offset
    // vc_end_offset
    // clear value
    // renderpass_begin_info
    for (size_t i = 0; i < vc_pipelines.size(); i++)
    {
        // if endoffsets - startoffset = 0, continue
        // beginRenderPass
        // bindPipeline
        
        // BindDescriptorSet // for Uniforms
        // cmdDraw
        // endRenderPass
    }
}

void IngDrawManager::drawIngObject(uint32_t current_swapchain_image_index)
{
    prepareDrawBuffer(current_swapchain_image_index);
    drawPointLineTriangleBox(current_swapchain_image_index);
    // drawWireFrameObject()
}


INNO_NAMESPACE_END
