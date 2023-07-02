#include "Mesh.h"

Mesh::Mesh(const float* buffer, size_t vertices, const int* attrs) : vertices(vertices) {
	int vertex_size = 0;
	for (int i = 0; attrs[i]; i++) {
		vertex_size += attrs[i];
	}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertex_size * vertices, buffer, GL_STATIC_DRAW);

	// attributes
	int offset = 0;
	for (int i = 0; attrs[i]; i++) {
		int size = attrs[i];

		// Position
		// 1 parametr - layout(location = number) in vertexshader
		// 5 parametr - step into massive vertices
		// 6 parametr - start to read info about vertex
		glVertexAttribPointer(i, size, GL_FLOAT, GL_FALSE, vertex_size * sizeof(float), (GLvoid*)(offset * sizeof(float)));
		glEnableVertexAttribArray(i);
		offset += size;
	}

	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Mesh::draw(unsigned int primitive) {
	glBindVertexArray(VAO);
	glDrawArrays(primitive, 0, vertices);  // 3 parametr - number of vertices
	glBindVertexArray(0);
}
