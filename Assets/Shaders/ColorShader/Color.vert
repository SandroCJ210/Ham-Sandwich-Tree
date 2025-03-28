#version 330 core

layout(location = 0) in vec3 _position;

uniform mat4 _model;
uniform mat4 _view;
uniform mat4 _projection;

void main(){
    gl_Position = _projection * _view * _model * vec4(_position, 1.0);
}
