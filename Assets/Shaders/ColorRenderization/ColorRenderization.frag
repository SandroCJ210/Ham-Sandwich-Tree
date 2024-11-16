#version 330 core

uniform vec3 _color;

out vec4 FragColor;

void main(){
    FragColor = vec4(_color, 1.0);
}