#include "editor/include/editor.h"

#include "runtime/core/base/macro.h"
#include "runtime/engine.h"
#include "runtime/function/global/global_context.h"

// render_camera
#include "runtime/function/render/render_system.h"

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
    LOG_INFO("Editor Construct");
}

InnoEditor::~InnoEditor() {
    LOG_INFO("Editor Destruct");
}

void InnoEditor::initialize(InnoEngine* engine_runtime) {
    assert(engine_runtime);

    m_engine_runtime = engine_runtime;
    EditorGlobalContextInitInfo init_info = {
        g_runtime_global_context.m_window_system.get(),
        g_runtime_global_context.m_render_system.get(),
        engine_runtime
    };
    g_editor_global_context.initialize(init_info);
    // scene manager
    // editor ui

    LOG_INFO("Editor Init");
}

void InnoEditor::clear() { 
    g_editor_global_context.clear(); 
}

void InnoEditor::run()
{
    assert(m_engine_runtime);
    // asssert editor ui
    float delta_time;
    LOG_INFO("Will Run Engine");
    while (true)
    {
        delta_time =  m_engine_runtime->calculateDeltaTime();
        // scene_manager.tick
        // input_manager.tick
        if (!m_engine_runtime->tickOneFrame(delta_time)) {
            return;
        }
    }
}

INNO_NAMESPACE_END