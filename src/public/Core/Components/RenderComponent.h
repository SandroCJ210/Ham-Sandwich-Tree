#pragma once
#include "Core/Components/IComponent.h"
#include "Math/Vector3.h"

class AMaterial;

class RenderComponent : public IComponent {

public:
	AMaterial* material;

public:
	RenderComponent(AObject* parent);
	~RenderComponent() override;
	void LateUpdate() override;

private:
	void Draw();
};
