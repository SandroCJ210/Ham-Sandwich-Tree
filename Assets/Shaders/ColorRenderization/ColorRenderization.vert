#version 330 core

layout(location = 0) in vec3 _position;

out vec3 fragColor;

uniform vec3 color;

void main(){
    gl_Position = vec4(_position, 1.0);
    fragColor = color;
}
