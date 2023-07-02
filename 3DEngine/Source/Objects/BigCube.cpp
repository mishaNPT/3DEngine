#include "BigCube.h"

#include <iostream>

BigCube::BigCube(int number, float lenght, std::string textureFile, bool isPNG) {
	N = number;
	len = lenght;

	masCubes = new Cube* [N * N * N];

	srand(time(0));
	for (int k = 0; k < N; k++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if ((i + N * j + N * N * k) % 2 == 0) {
					float x = i * len * 1.9f;
					float y = j * len * 1.9f;
					float z = -k * len * 1.9f;
					float a = (float)(rand() % 255) / 255.0f;
					float b = (float)(rand() % 255) / 255.0f;
					float c = (float)(rand() % 255) / 255.0f;
					glm::vec3 color = glm::vec3(a, b, c);
					masCubes[i + N * j + N * N * k] = new Cube(x, y, z, len, color, textureFile, isPNG);
				}
			}
		}
	}
}

BigCube::~BigCube() {
	for (int i = 0; i < N * N * N; i += 2) {
		delete masCubes[i];
	}
	delete[] masCubes;
}

void BigCube::renderBigCube() {
	for (int i = 0; i < N * N * N; i += 2) {
		masCubes[i]->renderCube();
	}
}
