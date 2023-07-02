#pragma once

#include <string>

#include "glm/glm.hpp"

#include "../Graphics/Mesh.h"
#include "../Graphics/Texture.h"

class CubeModel {
private:
	Mesh* meshCube;
	Texture* textureCube;
};

class Cube {
private:
	float a;  // edge length
	float x, y, z;  // starting point
	glm::vec3 color;  // cube color

	bool isRendered = true;  // draw cube or not

	float buffer[12 * 3 * 9];
	int attributs[5] = {3, 3, 2, 1, 0};

	Mesh* meshCube;
	Texture* textureCube;

	void preRenderCube();  // creating buffer

public:
	Cube();
	Cube(float startX, float startY, float startZ, float edge, glm::vec3 color, std::string textureFile, bool isPNG = false);
	~Cube();

	void updateRender(bool render);  // updating variable isRendered
	void renderCube();
};
