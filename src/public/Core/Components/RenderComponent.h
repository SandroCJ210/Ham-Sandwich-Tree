#pragma once
#include "Core/Components/IComponent.h"
#include "Math/Vector3.h"

class AMaterial;

class RenderComponent : public IComponent {

public:
	AMaterial* material;
	float height = 1;
	float width = 1;

	float scale = 0.25;

private:
	float vertices[12];
	unsigned int indices[6];

	unsigned int VAO, VBO, EBO;

public:
	RenderComponent(AObject* parent);
	~RenderComponent() override;
	void Update() override;
	void LateUpdate() override;

private:
	void CalcVertex();
	void GenBuffers();
	void UpdateBuffers();
	void Draw();

public:
	void SetScale(float scale);
};
