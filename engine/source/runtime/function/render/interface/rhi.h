#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vma/vk_mem_alloc.h>

#include <memory>
#include <vector>
#include <functional>

#include "rhi_struct.h"

#include <common.h>

INNO_NAMESPACE_BEGIN

class WindowSystem;

struct RHIInitInfo
{
    std::shared_ptr<WindowSystem> window_system;
};

class RHI 
{
public:
    virtual ~RHI() = 0;
    virtual void initialize(RHIInitInfo initalize_info) = 0;
    virtual void prepareContext() = 0;
};

// TODO

INNO_NAMESPACE_END
