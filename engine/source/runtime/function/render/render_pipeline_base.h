#pragma once

// vector2
#include "runtime/function/render/render_pass_base.h"

#include <memory>
#include <vector>

INNO_NAMESPACE_BEGIN

// RHI
class RenderResourceBase;
// WindowUI

struct RenderPipelineInitInfo
{
    // enable fxaa
    // rendersource
};

class RenderPipelineBase
{
    friend class RenderSystem;

public:
    virtual ~RenderPipelineBase();
    virtual void preparePassData(std::shared_ptr<RenderResourceBase> render_resource);
protected:
    // rhi
    // m_directional_light_pass
    // m_point_light_shadow_pass
    // m_main_camera_pass
    // m_color_grading_pass
    // m_fxaa_pass
    // m_tone_mapping_pass
    // m_ui_pass
    // m_combine_ui_pass
    // m_pick_pass
    // m_particle+pass
};

INNO_NAMESPACE_END
