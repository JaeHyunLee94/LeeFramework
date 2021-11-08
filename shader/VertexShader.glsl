#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec3 normal;

out vec3 v_normal;
out vec3 v_view;

uniform mat4 modelMat,viewMat,projMat;
uniform vec3 eyepos;
//uniform vec3 base_color;

void main(){


    v_normal=normalize(transpose(inverse(mat3(modelMat)))*normal); //world normal
    vec3 worldPos=(modelMat*vec4(position,1.0)).xyz; // world pos
    v_view=normalize(eyepos-worldPos); //view vector
    //v_color=base_color;
    gl_Position=projMat*viewMat*vec4(worldPos,1.0);

}