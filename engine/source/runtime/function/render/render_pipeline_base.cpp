#include "runtime/function/render/render_pipeline_base.h"
#include "runtime/function/render/ingdraw/ing_draw_manager.h"
#include "runtime/core/base/macro.h"
#include "runtime/function/global/global_context.h"

INNO_NAMESPACE_BEGIN

void RenderPipelineBase::preparePassData(std::shared_ptr<RenderResourceBase> render_resource)
{
    // main_camera_pass
    // m_pick_pass
    // m_directional_light_pass
    // m_point_light_shadow_pass
    // m_particle_pass
    g_runtime_global_context.m_ing_draw_manager->preparePassData(render_resource);
}

INNO_NAMESPACE_END
