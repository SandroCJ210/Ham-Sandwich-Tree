#include "Core/Render/Render.h"
#include <glad/glad.h>
#include <iostream>

Render::Render() {

	InitQuad();
	InitLine();
	test = 15;
}

Render::~Render() {

}

void Render::InitQuad() {

	glGenVertexArrays(1, &VAO_quad);

	glBindVertexArray(VAO_quad);
	
	glGenBuffers(1, &VBO_quad);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_quad);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);

	glGenBuffers(1, &EBO_quad);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_quad);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), nullptr, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

}

void Render::InitLine() {
	/*glGenVertexArrays(1, &VAO_line);
	glBindVertexArray(VAO_line);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);*/
}

void Render::DrawLine(unsigned int *VBO) {
	/*glBindVertexArray(VAO_line);
	glBindBuffer(GL_ARRAY_BUFFER, *VBO);
	glDrawArrays(GL_LINES, 0, 2);*/
}

void Render::DrawQuad(float* vertices, int verticesSize, unsigned int* indices, int indicesSize) {


	glBindVertexArray(VAO_quad);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_quad);
	glBufferSubData(GL_ARRAY_BUFFER, 0, verticesSize, vertices);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_quad);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indicesSize, indices);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}