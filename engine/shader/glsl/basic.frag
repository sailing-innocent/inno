#version 460 core

layout(location = 0) in vec4 vertexColor;
layout(location = 0) out vec4 FragColor;

uniform vec4 ourColor;

vec4 mix(vec4 color1, vec4 color2) {
    return (color1 + color2) / 2;
}

void main() {
    // FragColor = vertexColor;
    FragColor = mix(ourColor, vertexColor);
}