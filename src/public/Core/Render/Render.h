#pragma once
#include "Util/Singleton.h"

class Render : public Singleton<Render> {
private:
	unsigned int VAO_quad;
	unsigned int VBO_quad;
	unsigned int EBO_quad;
	unsigned int VAO_line;
	unsigned int VBO_line;

public:
	int test;
	Render();
	~Render();
private:
	void InitQuad();
	void InitLine();

public:
	void DrawQuad(float* vertices);
	void DrawLine(float* vertices);
};

template class Singleton<Render>;