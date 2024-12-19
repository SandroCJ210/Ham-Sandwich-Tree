#pragma once
#include "Core/Components/IComponent.h"

class AMaterial;

class RenderComponent : public IComponent {

public:
	bool enableRender = true;
	AMaterial* material;

public:
	RenderComponent(AObject* parent);
	~RenderComponent() override;
	void LateUpdate() override;

private:
	void Draw();
};
