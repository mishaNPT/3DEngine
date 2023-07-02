#pragma once

#include <string>

#include "glm/glm.hpp"

#include "../Graphics/Mesh.h"
#include "../Graphics/Texture.h"

class Object {
private:
	float x, y, z;  // starting point
	bool isRendered = true;  // draw cube or not

	Mesh* meshCube;
	Texture* textureCube;

	void loadObject();

public:
	Object();
	Object(float startX, float startY, float startZ, std::string fileNameObj);
	Object(float startX, float startY, float startZ, std::string fileNameObj, std::string fileNameMtl);
	~Object();

	void render();
};

