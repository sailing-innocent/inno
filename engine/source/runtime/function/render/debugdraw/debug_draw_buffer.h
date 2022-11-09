#pragma once

#include "runtime/function/render/interface/rhi.h"
#include "debug_draw_primitive.h"
// #include "debug_draw_font.h"

#include <queue>

INNO_NAMESPACE_BEGIN

class DebugDrawAllocator
{
public:
    DebugDrawAllocator() {};
    // initialize
    // destroy
    // tick
    // clear
    // clearBuffer

    // cacheVertex
    // cacheUniformObject
    // cacheUniformDynamicObject
    
    // getVertexCacheOffset
    // getUniformDynamicCacheOffset
    // allocator
    
    // getVertexBuffer
    // getDescriptorSet
    
    // getSphereVertexBuffer
    // getCylinderVertexBuffer
    // getCapsuleVertexBufferUpSize
    // getCapsuleVertexBufferMidSize
    // getCapsuleVertexBufferDownSize

    // getSizeOfUniformBufferObject
private:
    std::shared_ptr<RHI> m_rhi;
    struct UniformBufferObject
    {};

    // UniformBufferDynamicObject
    
    struct Resource
    {
        RHIBuffer* buffer = nullptr;
        RHIDeviceMemory* memory = nullptr;
    };

    struct Descriptor
    {
        RHIDescriptorSetLayout* layout = nullptr;
        std::vector<RHIDescriptorSet*> descriptor_set;
    };

    Descriptor m_desriptor;

    // Changable Resource
    Resource m_vertex_resource;
    std::vector<DebugDrawVertex> m_vertex_cache;

    Resource m_uniform_resource;
    //
    Resource m_uniform_dynamic_resource;
    //

    // static mesh resource
    Resource m_sphere_resource;
    Resource m_cylinder_resource;
    Resource m_capsule_resource;

    // font resource
    
    // resrouce deleter
private:
    // setupDescriptorSet
    // prepareDescriporSet
    // updateDescriptorSet
    // flushPendingDelete
    // unloadMeshBuffer
    // loadSphereMeshBuffer
    // loadCylinderMeshBuffer
    // loadCapsuleMeshBuffer

    const int m_circle_sample_count = 10;
};

INNO_NAMESPACE_END
