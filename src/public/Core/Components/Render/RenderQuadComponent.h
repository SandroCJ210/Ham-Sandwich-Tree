#pragma once
#include "Core/Components/IComponent.h"

class AMaterial;

class RenderQuadComponent : public IComponent {

public:
	bool enableRender = true;
	AMaterial* material;

public:
	RenderQuadComponent(AObject* parent);
	~RenderQuadComponent() override;
	void LateUpdate() override;

private:
	void Draw();
};
