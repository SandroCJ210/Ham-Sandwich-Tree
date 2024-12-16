#pragma once
#include "Util/Singleton.h"
#include "Math/Vector3.h"
#include <vector>
#include <string>

class Shader;
class GizmosMaterial;

class Render : public Singleton<Render> {
private:
	std::vector<Shader*> shaders;
	unsigned int VAO_quad;
	unsigned int VBO_quad;
	unsigned int EBO_quad;
	unsigned int VAO_line;
	unsigned int VBO_line;

	GizmosMaterial* gizmosMaterial;

public:
	Render();
	~Render();

private:
	void InitQuad();
	void InitLine();

	Vector3 TransformWorldToScreen(Vector3 worldScale);

public:
	Shader* CreateShader(const std::string vertexPath, const std::string fragmentPath);
	void DrawQuad(Vector3 center, Vector3 size);
	void DrawLineSegment(Vector3 start, Vector3 end, Vector3 color);
	void DrawQuadLine(Vector3 center, Vector3 size, Vector3 color);
};

template class Singleton<Render>;