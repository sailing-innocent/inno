#pragma once

/**
 * @file: runtime/function/render/render_scene.h
 * @author: sailing-innocent
 * 
*/

// object_id_allocator
// light
// render_common
// render_entity
// render_guid_allocator
// render_object

#include <optional>
#include <vector>

#include <common.h>

INNO_NAMESPACE_BEGIN

class RenderResource;
class RenderCamera;

class RenderScene
{
public:
    // m_ambient_light
    // m_directional_light
    // m_point_light_list
    // m_render_entities
    // m_render_axis
    // m_directional_light_visible_mesh_nodes
    // m_point_lights_visible_mesh_nodes
    // m_main_camera_visible_mesh_nodes
    // m_axis_node
    
    // clear

    // update visible objects in each frame

    // setVisible nodes ptr in render pass

private:
    // m_mesh_asset_id_allocator
    
};

INNO_NAMESPACE_END

