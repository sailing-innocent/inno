#pragma once

#include <common.h>

INNO_NAMESPACE_BEGIN

struct EditorGlobalContextInitInfo
{
    class WindowSystem* window_system;
    class RenderSystem* render_system;
    class InnoEngine* engine_runtime;
};


class EditorGlobalContext
{
public:
    // Scene Manager
    // Input Manager
    class RenderSystem* m_render_system {nullptr};
    class WindowSystem* m_window_system {nullptr};
    class InnoEngine* m_engine_runtime {nullptr};
public:
    void initialize(const EditorGlobalContextInitInfo& init_info);
    void clear();
};

extern EditorGlobalContext g_editor_global_context;

INNO_NAMESPACE_END
