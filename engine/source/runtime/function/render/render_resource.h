#pragma once

#include "runtime/function/render/render_resource_base.h"
// render_type
// rhi
// render_common

// vk_mem_alloc
// vulkan

#include <array>
#include <cstdint>
#include <map>
#include <vector>
#include <cmath>

INNO_NAMESPACE_BEGIN

// RHI
class RenderPassBase;
// RenderCamera

struct IBLResource {};

struct IBLResourceData {};

struct ColorGradingResource {};

struct ColorGradingResourceData {};

struct StorageBuffer {};

struct GlobalRenderResource
{
    // IBLResource
    // ColorGradingResource
    // StorageBuffer
};

class RenderResource : public RenderResourceBase
{
public:

};

INNO_NAMESPACE_END