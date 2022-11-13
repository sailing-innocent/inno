#pragma once

#include "ing_draw_primitive.h"

#include <string>
#include <mutex>
#include <list>

INNO_NAMESPACE_BEGIN

class IngDrawGroup
{
private:
    std::mutex m_mutex;
    std::string m_name;
    std::list<IngDrawPoint> m_points;
    std::list<IngDrawLine> m_lines;
    std::list<IngDrawTriangle> m_triangles;
    std::list<IngDrawQuad> m_quad;

public:
    virtual ~IngDrawGroup();
    // void initliaze();
    // void clear();
    // void clearData();
    void setName(const std::string& name);
    const std::string& getName() const;

    // void addPoint();
    // void addLine();
    // void addTriangle();
    // void addQuad();

    // removeDeadPrimitive
    // void mergeFrom(IngDrawGroup* group);

    // getPointCount
    // getLineCount
    // getTriangleCount
    // getUniformDynamicDataCount
    
    // writePointData(std::vector<IngDrawVertex>& vertices)
    // writeLineData(std::vector<IngDrawVertex>& vertices)
    // writeTriangleData(std::vector<DebugDrawVertex>& vertices)

    // writeUniformDynamicDataToCache(datas)
};

INNO_NAMESPACE_END
