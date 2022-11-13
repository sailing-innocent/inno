#pragma once

// include ing
// include sail
#include "common.h"
#include <cstdint>

INNO_NAMESPACE_BEGIN

// k_debug_draw_infinity_life_time
// k_debug_draw_one_frame

// DebugDrawTimeType

enum IngDrawPrimitiveType: uint8_t
{
    _ing_draw_primitive_type_point = 0,
    _ing_draw_primitive_type_line,
    _ing_draw_primitive_type_triangle,
    _ing_draw_primitive_type_quad,
};

// Fill Mode

struct IngDrawVertex
{
    // sail vec3 pos;
    // sail vec4 color;
    // texcoord
    IngDrawVertex() {
        // pos = 
        // color = 
    }

    // VertexInputBindingDescription
    // VertexInputAttributeDescription

};

class IngDrawPrimitive
{
    // m_type_type
    // m_life_time
    // m_fill_mode
    // depth test
    // is time out
    // set time
};

class IngDrawPoint: public IngDrawPrimitive
{
public:
    IngDrawVertex m_vertex;
    static const IngDrawPrimitiveType k_type_enum_value = _ing_draw_primitive_type_point;
};

class IngDrawLine: public IngDrawPrimitive
{
public:
    IngDrawVertex m_vertex[2];
    static const IngDrawPrimitiveType k_type_enum_value = _ing_draw_primitive_type_line;
};

class IngDrawTriangle: public IngDrawPrimitive
{
public:
    IngDrawVertex m_vertex[3];
    static const IngDrawPrimitiveType k_type_enum_value = _ing_draw_primitive_type_triangle;
};

class IngDrawQuad: public IngDrawPrimitive
{
public:
    IngDrawVertex m_vertex[4];
    static const IngDrawPrimitiveType k_type_enum_value = _ing_draw_primitive_type_quad;
};

INNO_NAMESPACE_END
