#pragma once

#include "ing_draw_group.h"
#include <vector>

INNO_NAMESPACE_BEGIN

class IngDrawContext
{
public:
    std::vector<IngDrawGroup*> m_ing_draw_groups;
    IngDrawGroup* tryGetOrCreateIngDrawGroup(const std::string& name);
    void clear();
    void tick(float delta_time);
private:
    std::mutex m_mutex;
    // void removeDeadPrimitives(float delta_time);
};

INNO_NAMESPACE_END
