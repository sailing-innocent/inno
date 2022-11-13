#include "ing_draw_manager.h"
// global context
// render system
// math

INNO_NAMESPACE_BEGIN

// initialize
// get app -> setupPipeline
void IngDrawManager::initialize() {
    // get app
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
    // not update when ticking
    // allocator->tick() update parameter
    // m_ing_draw_context->tick() // remove dead primitives
}



INNO_NAMESPACE_END
