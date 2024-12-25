#version 330 core

in vec2 uv;
out vec4 FragColor;

uniform vec3 _color;
uniform sampler2D _texture;

void main(){
    FragColor = texture(_texture, uv) * vec4(_color, 1.0);
}