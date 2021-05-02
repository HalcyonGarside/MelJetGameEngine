#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 tPos;

uniform vec3 i_col;


out vec3 o_col;
out vec2 t_coord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
	o_col = i_col;
	t_coord = tPos;
}