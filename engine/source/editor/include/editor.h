#pragma once
// include vector2

#include <memory>
#include <string>
#include <common.h>

INNO_NAMESPACE_BEGIN

class EditorUI;
class InnoEngine;
class InnoEditor
{
    friend class EditorUI;
public:
    InnoEditor();
    virtual ~InnoEditor();

    void initialize(InnoEngine* engine_runtime);
    void clear();

    void run();

protected:
    std::shared_ptr<EditorUI> m_editor_ui;
    InnoEngine* m_engine_runtime{nullptr};
};

INNO_NAMESPACE_END