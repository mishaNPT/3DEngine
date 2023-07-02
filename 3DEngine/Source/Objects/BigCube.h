#pragma once

#include <string>

#include "Cube.h"

class BigCube {
private:
	int N;
	Cube** masCubes;
	float len = 1.0f;

public:
	BigCube(int number, float lenght, std::string textureFile, bool isPNG);
	~BigCube();

	void renderBigCube();
};
