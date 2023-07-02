#include "Cube.h"

#define VERTEX(INDEX, X, Y, Z, R, G, B, U, V, L)  buffer[INDEX + 0] = (X);\
												  buffer[INDEX + 1] = (Y);\
												  buffer[INDEX + 2] = (Z);\
												  buffer[INDEX + 3] = (R);\
												  buffer[INDEX + 4] = (G);\
												  buffer[INDEX + 5] = (B);\
												  buffer[INDEX + 6] = (U);\
												  buffer[INDEX + 7] = (V);\
												  buffer[INDEX + 8] = (L);\
												  INDEX += 9;

Cube::Cube() {
	x = 0;
	y = 0;
	z = 0;
	a = 0.0f;
}

Cube::Cube(float startX, float startY, float startZ, float edge, glm::vec3 color, std::string textureFile, bool isPNG) {
	x = startX;
	y = startY;
	z = startZ;
	a = edge;

	this->color = color;

	textureCube = new Texture(textureFile, (int)isPNG);

	preRenderCube();
}

Cube::~Cube() {
	delete meshCube;
	delete textureCube;
}

void Cube::updateRender(bool render) {
	isRendered = render;
}

void Cube::preRenderCube() {
	int index = 0;
	float light;
	// up face
	light = 1.0f;
	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + a, y + a, z, color.x, color.y, color.z, 1, 1, light);
	VERTEX(index, x + a, y + a, z - a, color.x, color.y, color.z, 0, 1, light);

	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + a, y + a, z - a, color.x, color.y, color.z, 0, 1, light);
	VERTEX(index, x, y + a, z - a, color.x, color.y, color.z, 0, 0, light);

	// front face
	light = 0.65f;
	VERTEX(index, x, y, z, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x + a, y, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + a, y + a, z, color.x, color.y, color.z, 1, 1, light);

	VERTEX(index, x, y, z, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x + a, y + a, z, color.x, color.y, color.z, 1, 1, light);
	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 0, 1, light);

	// right face
	light = 0.8f;
	VERTEX(index, x + a, y, z, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x + a, y, z - a, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + a, y + a, z - a, color.x, color.y, color.z, 1, 1, light);

	VERTEX(index, x + a, y, z, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x + a, y + a, z - a, color.x, color.y, color.z, 1, 1, light);
	VERTEX(index, x + a, y + a, z, color.x, color.y, color.z, 0, 1, light);

	// left face
	light = 0.8f;
	VERTEX(index, x, y, z - a, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x, y, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 1, light);

	VERTEX(index, x, y, z - a, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 1, light);
	VERTEX(index, x, y + a, z - a, color.x, color.y, color.z, 0, 1, light);

	// bottom face
	light = 0.7f;
	VERTEX(index, x, y, z - a, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x + a, y, z - a, color.x, color.y, color.z, 0, 1, light);
	VERTEX(index, x + a, y, z, color.x, color.y, color.z, 1, 1, light);

	VERTEX(index, x, y, z - a, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x + a, y, z, color.x, color.y, color.z, 1, 1, light);
	VERTEX(index, x, y, z, color.x, color.y, color.z, 1, 0, light);

	// back face
	light = 0.85f;
	VERTEX(index, x + a, y, z - a, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x, y, z - a, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x, y + a, z - a, color.x, color.y, color.z, 1, 1, light);

	VERTEX(index, x + a, y, z - a, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x, y + a, z - a, color.x, color.y, color.z, 1, 1, light);
	VERTEX(index, x + a, y + a, z - a, color.x, color.y, color.z, 0, 1, light);
	
	meshCube = new Mesh(buffer, 12 * 3, attributs);
}

void Cube::renderCube() {
	if (isRendered) {
		textureCube->bind();
		meshCube->draw(GL_TRIANGLES);
	}
}
