#include <editor/include/editor_global_context.h>

// editor_input_manager
// editor_scene_manager

// render_system
// window_system

INNO_NAMESPACE_BEGIN

EditorGlobalContext g_editor_global_context;

void EditorGlobalContext::initialize(const EditorGlobalContextInitInfo& init_info)
{
    g_editor_global_context.m_window_system = init_info.window_system;
    g_editor_global_context.m_render_system = init_info.render_system;
    g_editor_global_context.m_engine_runtime = init_info.engine_runtime;

    // scene_manager
    // input_manager
}

void EditorGlobalContext::clear()
{
    // del scene manager
    // del input manager
}

INNO_NAMESPACE_END
