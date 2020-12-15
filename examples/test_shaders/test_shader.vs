#version 410 core

layout (location = 0) in vec3 aPos;
uniform vec3 i_col;

out vec3 o_col;
void main()
{
    gl_Position = vec4(aPos, 1.0);
	o_col = i_col;
}