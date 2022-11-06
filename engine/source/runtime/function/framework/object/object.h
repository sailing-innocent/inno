#pragma once

// depend on component.h
// object id allocator
// resource common object

#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

namespace inno
{
class GObject: public std::enable_shared_from_this<GObject>
{
    // typedef std::unordered_set<std::string> TypeNameSet;
public:
    // GObject(GObjectID id): m_id {id} {}
    virtual ~GObject();
    virtual void tick(float delta_time);
    // load
    // save
    // getID
    // hasComponent
    // tryGetComponent
    // tryGetComponentConst
protected:
    // m_id
    std::string m_name;
    std::string m_difinition_url;
    // Reflection m_components;
};

// define tryGetComponent
// define tryGetComponentConst
}