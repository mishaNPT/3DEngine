#pragma once

#include "Window.h"

#include <glm/ext.hpp>
#include "glm/glm.hpp"
using namespace glm;

class Camera {
private:
	void updateVectors();
public:
	vec3 front;
	vec3 up;
	vec3 right;

	float camX = 0.0f;
	float camY = 0.0f;

	float speed = 5.0f;

	vec3 position;
	float fov;
	mat4 rotation;
	mat4 model = mat4(1.0f);
	Camera(vec3 position, float fov);

	void rotate(float x, float y, float z);

	mat4 getProjection();
	mat4 getView();
};
