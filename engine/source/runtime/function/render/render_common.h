#pragma once

// matrix4
// vector3
// vector4

#include "runtime/function/render/render_type.h"
#include "interface/rhi.h"

#include <vma/vk_mem_alloc.h>
#include <vulkan/vulkan.h>

#include <common.h>

INNO_NAMESPACE_BEGIN

// static const uint32_t s_point_light_shadow_map_dimension = 2048;
// static const uint32_t s_directional_light_shadow_map_dimension = 4096;
// 64 Should be best
// static uint32_t const s_mesh_per_drawcall_max_instance_count = 64;
// static uint32_t const s_mesh_vertex_blending_max_joint_count = 1024;
// static uint32_t const s_max_point_light_count = 15;

struct VulkanSceneDirectionalLight {};

struct VulkanScenePointLight {};

struct MeshPerframeStorageBufferObject
{
    // proj_view_matrix
    // camera_position
    // _padding_camera_position
    // ambient_light
    // _padding_ambient_light
    // point_light_num
    // _padding_point_light_num_1;
    // _padding_point_light_num_2;
    // _padding_point_light_num_3;
    // Scene Point Light
    // Scene Directional Light
    // directional_light_proj_view
};

struct VulkanMeshInstance
{
    // float enable_vertex_blending;
    // _padding_enable_vertex_blending_1
    // _padding_enable_vertex_blending_2
    // _padding_enable_vertex_blending_3
    // model_matrix
};

struct VulkanMesh
{
    // enable_vertex_blending
    uint32_t mesh_vertex_count;
    
    RHIBuffer* mesh_vertex_position_buffer;
    VmaAllocation mesh_vertex_position_buffer_allocation;

    // varying
    // joint binding
    uint32_t mesh_index_count;
    RHIBuffer* mesh_index_buffer;
    VmaAllocation mesh_index_buffer_allocation;
};

struct VulkanPBRMaterial
{
    // RHIImage* base_color_texture_image;
    // RHIImageVieww
    // VmaAllocation

    // roughness texture image


    // normal_texture_image
    // emissive_texture_image

    // material_uniform_buffer
    
    // material_descriptor_set
};



INNO_NAMESPACE_END

