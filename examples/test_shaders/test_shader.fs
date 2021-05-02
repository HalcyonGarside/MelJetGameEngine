#version 410 core

out vec4 color;
in vec3 o_col;
in vec2 t_coord;

uniform sampler2D myTex;
void main()
{
    //color = vec4(o_col, 1.f);
    color = mix(vec4(o_col, 1.f), texture(myTex, t_coord), 0.25f);
}