#pragma once
#include "Core/Components/IComponent.h"

class AMaterial;

class RenderCubeComponent : public IComponent {
public:
	bool enableRender = true;
	AMaterial* material;

public:
	RenderCubeComponent(AObject* parent);
	~RenderCubeComponent() override;
	void LateUpdate() override;

private:
	void Draw();
};
