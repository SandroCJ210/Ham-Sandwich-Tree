#pragma once
#include "Core/Components/IComponent.h"
#include "Math/Vector3.h"

class AMaterial;

class RenderComponent : public IComponent {

public:
	AMaterial* material;
	float height = 1;
	float width = 1;

	Vector3 scale = Vector3(2.0f/3.0f);

private:
	float vertices[12];
	unsigned int indices[6];

public:
	RenderComponent(AObject* parent);
	~RenderComponent() override;
	void LateUpdate() override;

private:
	void CalcVertex();
	void GenBuffers();
	void UpdateBuffers();
	void Draw();

public:
	void SetScale(Vector3 scale);
};
