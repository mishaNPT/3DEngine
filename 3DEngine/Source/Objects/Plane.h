#pragma once

#include <string>

#include "glm/glm.hpp"

#include "../Graphics/Mesh.h"
#include "../Graphics/Texture.h"

class Plane {
private:
	float x, y, z, a, b;  // starting point
	glm::vec3 color;  // cube color

	bool isRendered = true;  // draw cube or not

	float buffer[4 * 3 * 9];
	int attributs[5] = { 3, 3, 2, 1, 0 };

	Mesh* meshPlane;
	Texture* texturePlane;

	void preRenderPlane();

public:
	Plane();
	Plane(float startX, float startY, float startZ, float lenght, float width, glm::vec3 color, std::string textureFile, bool isPNG = false);
	~Plane();

	void updateRender(bool render);  // updating variable isRendered
	void renderPlane();
};
