#include "editor/include/editor.h"

#include "runtime/engine.h"
#include "function/global/global_context.h"

// render_camera
// render_system

#include "editor/include/editor_global_context.h"
// editor_input_manager
// editor_scene_manager
// editor_ui

#include <common.h>

INNO_NAMESPACE_BEGIN

void registerEditorTickComponent(std::string component_type_name)
{
    
}

InnoEditor::InnoEditor()
{
    // registerEditorTickComponent
}

InnoEditor::~InnoEditor() {}

void InnoEditor::initialize(InnoEngine* engine_runtime) {
    assert(engine_runtime);

    m_engine_runtime = engine_runtime;

    // set global variable

}

void InnoEditor::clear() { g_editor_global_context.clear(); }

void InnoEditor::run()
{
    assert(m_engine_runtime);
    // asssert editor ui
    float delta_time;
    while (true)
    {
        // delta_time =  calcuateDeltaTime()
        // scene_manager.tick
        // input_manager.tick
        // m_engine_runtime->tick_one_frame(delta_time)
    }
}

INNO_NAMESPACE_END