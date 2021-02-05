#version 410 core

out vec4 color;
in vec3 o_col;
in vec2 t_coord;

uniform sampler2D myTex;
void main()
{
    //color = vec4(o_col, 1.f);
    color = texture(myTex, t_coord);
}