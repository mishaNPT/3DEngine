#version 330 core

in vec4 a_color;
in vec2 a_texture;
in float a_light;

out vec4 f_color;

uniform int isTextured;
uniform sampler2D u_texture;

void main() {
	if (isTextured == 1) {
		f_color = vec4(a_light * texture(u_texture, a_texture).x, a_light * texture(u_texture, a_texture).y, a_light * texture(u_texture, a_texture).z, 1.0f);
	} else if (isTextured == 0) {
		f_color = a_color;
	}
}
