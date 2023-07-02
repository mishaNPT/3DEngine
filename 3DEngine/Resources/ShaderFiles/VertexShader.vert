#version 330 core

layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_color;
layout(location = 2) in vec2 v_texture;
layout(location = 3) in float v_light;

out vec4 a_color;
out vec2 a_texture;
out float a_light;

uniform mat4 model;
uniform mat4 projview;

void main() {
	a_color = vec4(v_color.x * v_light, v_color.y * v_light, v_color.z * v_light, 1.0f);
	a_texture = v_texture;
	a_light = v_light;
	gl_Position = projview * model * vec4(v_position, 1.0);
}
