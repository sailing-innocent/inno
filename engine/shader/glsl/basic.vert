#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

layout (location = 0) out vec4 vertexColor;

// uniform mat4 transform;

uniform float t;

void main()
{ 
    // gl_Position = transform * vec4(aPos, 1.0f);
    float wav1 =  0.4 * sin(t + 10 * aPos[0]);
    float wav2 =  0.4 * sin(2 * t + 5 * aPos[0]);
    gl_Position = vec4(aPos[0], wav1 + wav2, aPos[2], 1.0);
    vertexColor = vec4(aColor, 1.0);
}