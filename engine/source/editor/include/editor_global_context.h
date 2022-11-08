#pragma once

#include <common.h>

INNO_NAMESPACE_BEGIN

struct EditorGlobalContextInitInfo
{
    // window_system
    // render_system
    // engine_runtime
};

class EditorGlobalContext
{
public:
    // EditorSceneManager
    // EditorInputManager
    // RenderSystem
    // WindowSystem
    // InnoEngine
public:
    void initialize(const EditorGlobalContextInitInfo& init_info);
    void clear();
};

extern EditorGlobalContext g_editor_global_context;

INNO_NAMESPACE_END
