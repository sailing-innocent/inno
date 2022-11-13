#pragma once

#include "ing_draw_primitive.h"

INNO_NAMESPACE_BEGIN

struct IngDrawFrameBufferAttachment {
    // image
    // DeviceMemory
    // ImageView
    // Format
};

struct IngDrawFrameBuffer {
    // width
    // height
    // render_pass

    // framebuffers
    // attachments
};

struct IngDrawPipelineBase {
    // layout
    // primitive pipeline
};

enum IngDrawPipelineType: uint8_t
{
    _ing_draw_pipeline_type_point = 0,
    _ing_draw_pipeline_type_line,
    _ing_draw_pipeline_type_triangle,
    _ing_draw_pipeline_type_count
};

class IngDrawPipeline
{
public:
    IngDrawPipelineType m_pipeline_type;
    IngDrawPipeline(IngDrawPipelineType pipelineType) { m_pipeline_type = pipelineType; }
    void initialize();
    void destory();
    // get
    // getframebuffer
    // recreateAfterSwapChain
private:
    // setupAttatchments
    // setupframebuffer
    // setupRenderPass
    // setupDescriptorLayout
    // setupPipelines();

    // m_discriptor_layout
    // m_render_pipelines
    // m_framebuffer
    // rhi
};


INNO_NAMESPACE_END
