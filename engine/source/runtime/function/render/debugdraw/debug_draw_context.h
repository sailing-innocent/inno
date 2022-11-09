#pragma once

#include "debug_draw_group.h"

INNO_NAMESPACE_BEGIN

class DebugDrawContext
{
public:
    std::vector<DebugDrawGroup*> m_debug_draw_groups;
    // DebugDrawGroup* tryGetOrCreateDebugDrawGroup(const std::string& name);
    // void clear();
    // void tick(float delta_time);
private:
    std::mutex m_mutex;
    // removeDeadPrimitive(float delta_time)
};

INNO_NAMESPACE_END
