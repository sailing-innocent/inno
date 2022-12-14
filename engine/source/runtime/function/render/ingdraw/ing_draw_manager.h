#pragma once

#include "ing_draw_group.h"
#include "ing_draw_pipeline.h"
#include "runtime/function/render/render_resource.h"
#include "ing_draw_context.h"
// font

#include <ing/app/vk_canvas.hpp>

INNO_NAMESPACE_BEGIN

class IngDrawManager
{
public:
    IngDrawManager() {}
    void initialize();
    void setupPipelines();
    void preparePassData(std::shared_ptr<RenderResourceBase> render_resource);
    void destroy();
    void clear();
    void tick(float delta_time);
    // update after recreate swapchain
    // tryGetOrCreateIngDrawGroup(name)

    void draw(uint32_t current_swapchain_image_index);
    ~IngDrawManager() { destroy(); }

private:
    // swap data to render
    void drawIngObject(uint32_t current_swapchain_image_index);
    void prepareDrawBuffer(uint32_t current_swapchain_image_index);
    void drawPointLineTriangleBox(uint32_t current_swapchain_image_index);
    // drawWireFrameObject()

    std::mutex m_mutex;
    std::shared_ptr<ing::CanvasApp> m_app = nullptr;
    IngDrawPipeline* m_ing_draw_pipeline[IngDrawPipelineType::_ing_draw_pipeline_type_count] = {};
    // buffer allocator
    // draw context
    // group for render
    // font
    // proj_view_matrix

    size_t m_point_stat_offset;
    size_t m_point_end_offset;
    size_t m_line_start_offset;
    size_t m_line_end_offset;
    size_t m_triangle_start_offset;
    size_t m_triangle_end_offset;
    // no depth
    // text
};

INNO_NAMESPACE_END
