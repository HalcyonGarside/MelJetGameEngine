#version 410 core

out vec4 color;
in vec3 o_col;
void main()
{
    color = vec4(o_col, 1.f);
}