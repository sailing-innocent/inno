#pragma once

#include "runtime/function/render/interface/rhi.h"
// pipeline
// debug_draw_buffer
// render_resource
// context
// font

#include <common.h>

INNO_NAMESPACE_BEGIN

class DebugDrawManager
{
public:
    DebugDrawManager() {}
    // void initialize();
    // void setupPipeline();
    // void preparePassData
    // void destroy();
    // void clear();
    // void tick();
    // void updateAfterRecreateSwapChain
    // DebugDrawGrop
    // void draw()
    // ~DebugDrawManager()
private:
    // swapDataToRender
    // drawDebugObject
    // prepareDrawBuffer
    // drawPointLineTriangleBox
    // drawWireFrameObject

    std::mutex m_mutex;
    std::shared_ptr<RHI> m_rhi = nullptr;

    // DebugDrawPipeline
    // DebugDrawContext
    // DebugDrawGroup
    // DebugDrawFont
    // Matrix4x4 m_proj_view_matrix;

    size_t m_point_start_offset;
    size_t m_point_end_offset;
    size_t m_line_start_offset;
    size_t m_line_end_offset;
    size_t m_triangle_start_offset;
    size_t m_triangle_end_offset;
    size_t m_no_depth_test_point_start_offset;
    size_t m_no_depth_test_point_end_offset;
    size_t m_no_depth_test_line_start_offset;
    size_t m_no_depth_test_line_end_offset;
    size_t m_no_depth_test_triangle_start_offset;
    size_t m_no_depth_test_triangle_end_offset;
    size_t m_text_start_offset;
    size_t m_text_end_offset;
};

INNO_NAMESPACE_END
