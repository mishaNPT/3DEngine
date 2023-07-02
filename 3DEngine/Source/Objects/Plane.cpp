#include "Plane.h"

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

Plane::Plane() {
	x = 0;
	y = 0;
	z = 0;
}

Plane::Plane(float startX, float startY, float startZ, float lenght, float width, glm::vec3 color, std::string textureFile, bool isPNG) {
	x = startX;
	y = startY;
	z = startZ;
	a = lenght;
	b = width;

	this->color = color;

	texturePlane = new Texture(textureFile, (int)isPNG);

	preRenderPlane();
}

Plane::~Plane() {
	delete meshPlane;
	delete texturePlane;
}

void Plane::updateRender(bool render) {
	isRendered = render;
}

void Plane::renderPlane() {
	if (isRendered) {
		texturePlane->bind();
		meshPlane->draw(GL_TRIANGLES);
	}
}

void Plane::preRenderPlane() {  // сделать выбор на горизонтальную или ветикальную плоскость, и исправить координаты точек, чтобы плоскость рисовалась правильно
	int index = 0;
	float light;
	// up plane
	light = 1.0f;
	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + b, y + a, z, color.x, color.y, color.z, 1, 1, light);
	VERTEX(index, x + b, y, z, color.x, color.y, color.z, 0, 1, light);

	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + b, y, z, color.x, color.y, color.z, 0, 1, light);
	VERTEX(index, x + b, y + a, z, color.x, color.y, color.z, 0, 0, light);

	// bottom face
	light = 0.9f;
	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + b, y, z, color.x, color.y, color.z, 0, 1, light);
	VERTEX(index, x + b, y + a, z, color.x, color.y, color.z, 1, 1, light);

	VERTEX(index, x, y + a, z, color.x, color.y, color.z, 1, 0, light);
	VERTEX(index, x + b, y, z, color.x, color.y, color.z, 0, 0, light);
	VERTEX(index, x + b, y + a, z, color.x, color.y, color.z, 0, 1, light);

	meshPlane = new Mesh(buffer, 4 * 3, attributs);
}
