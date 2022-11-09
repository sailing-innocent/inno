#pragma once

#include "runtime/function/render/interface/rhi.h"
// #include "runtime/core/math/math_headers.h"

#include <array>

#include <common.h>

INNO_NAMESPACE_BEGIN

static const float k_debug_draw_infinity_life_time = -2.f;
static const float k_debug_draw_one_frame = 0.0f;

enum DebugDrawTimeType : uint8_t
{
    _debugDrawTimeType_infinity,
    _debugDrawTimeType_one_frame,
    _debugDrawTimeType_common
};

enum DebugDrawPrimitiveType: uint8_t
{
    _debug_draw_primitive_type_point = 0,
    _debug_draw_primitive_type_line,
    _debug_draw_primitive_type_triangle,
    _debug_draw_primitive_type_quad,
    _debug_draw_primitive_type_darw_box,
    _debug_draw_primitive_type_cylinder,
    _debug_draw_primitive_type_sphere,
    _debug_draw_primitive_type_capsule,
    _debug_draw_primitive_type_text,
    _debug_draw_primitive_type_count
};

enum FillMode: uint8_t 
{
    _FillMode_wireframe = 0,
    _FillMode_solid = 1,
    k_FillMode_count,
};

struct DebugDrawVertex
{
    // pos
    // color
    // texcoord
    DebugDrawVertex() {}
    // static getBindingDescription
    // static getAttributeDescription
};

class DebugDrawPrimitive
{
public:
    DebugDrawTimeType m_time_type{ _debugDrawTimeType_infinity };
    float m_life_time{ 0.f };
    FillMode m_fill_mode { _FillMode_wireframe };
    bool m_no_depth_test = false;
public:
    // bool isTimeOut(float delta_time);
    // void setTime(float in_life_time);
private:
    bool m_rendered = false;
};

class DebugDrawPoint: public DebugDrawPrimitive
{
public:
    DebugDrawVertex m_vertex;
    static const DebugDrawPrimitiveType k_type_enum_value = _debug_draw_primitive_type_point;
};

class DebugDrawLine: public DebugDrawPrimitive
{

};

// Triangle
// Quad
// Box
// Cylinder
// DrawSphere
// DrawText

INNO_NAMESPACE_END
