#pragma once

#include <stdlib.h>

#include "../Resources/Graphics.h"

class Mesh {
	GLuint VAO;
	GLuint VBO;
	size_t vertices;
public:
	Mesh(const float* buffer, size_t vertices, const int* attrs);
	~Mesh();

	void draw(unsigned int primitive);
};
