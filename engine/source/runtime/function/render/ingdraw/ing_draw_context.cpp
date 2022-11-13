#include "ing_draw_context.h"

INNO_NAMESPACE_BEGIN

IngDrawGroup* IngDrawContext::tryGetOrCreateIngDrawGroup(const std::string& name)
{
    std::lock_guard<std::mutex> guard(m_mutex);

    size_t ing_draw_group_count = m_ing_draw_groups.size();
    for (size_t ing_draw_group_index = 0; ing_draw_group_index < ing_draw_group_count; ing_draw_group_index++)
    {
        IngDrawGroup* ing_draw_group = m_ing_draw_groups[ing_draw_group_index];
        if (ing_draw_group->getName() == name)
        {
            return ing_draw_group;
        }
    }
    // not found create one
    IngDrawGroup* new_ing_draw_group = new IngDrawGroup;
    // new_ing_draw_group->initialize();
    m_ing_draw_groups.push_back(new_ing_draw_group);

    return new_ing_draw_group;
}

void IngDrawContext::clear() 
{
    std::lock_guard<std::mutex> guard(m_mutex);

    size_t ing_draw_group_count = m_ing_draw_groups.size();
    for (size_t ing_draw_group_index = 0; ing_draw_group_index < ing_draw_group_count; ing_draw_group_index++)
    {
        delete m_ing_draw_groups[ing_draw_group_index];
    }
}

void IngDrawContext::tick(float delta_time)
{
    // removeDeadPrimitives
}

INNO_NAMESPACE_END
