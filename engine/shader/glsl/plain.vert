#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

layout (location = 0) out vec4 vertexColor;

void main()
{ 
    // gl_Position = transform * vec4(aPos, 1.0f);
    gl_Position = vec4(aPos, 1.0);
    vertexColor = vec4(aColor, 1.0);
}