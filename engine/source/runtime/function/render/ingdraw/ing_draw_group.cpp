#include "ing_draw_group.h"
#include <vector>
// global context
// render_system

INNO_NAMESPACE_BEGIN

IngDrawGroup::~IngDrawGroup() {}

void IngDrawGroup::setName(const std::string& name) { m_name = name; }

const std::string& IngDrawGroup::getName() const { return m_name; }


INNO_NAMESPACE_END
