#pragma once

#include "debug_draw_primitive.h"

#include <mutex>
#include <list>

INNO_NAMESPACE_BEGIN

class DebugDrawGroup
{
private:
    std::mutex m_mutex;
    std::string m_name;
    std::list<DebugDrawPoint> m_points;
    // ...
public:
    // virtual ~DebugDrawGroup();
    // void initialize();
    // void clear()
    // void clearData()
    // void setName()
    // getName()
    // addPoint
    // addLine
    // addTriangle
    // addQuad
    // addBox
    // addCylinder
    // addCapsule
    // addText

    // removeDeadPrimitives
    // mergeFrom

    // getPointCount
    // getLineCount
    // getTriangleCount
    // writeUniformDynamicDataToCache
    // writeTextData

    // getSphereCount
    // getCylinderCount
    // getCapsuleCount
    // getTextCharacterCount
};

INNO_NAMESPACE_END
