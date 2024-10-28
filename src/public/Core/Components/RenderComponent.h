#pragma once
#include "Core/Components/IComponent.h"

class AMaterial;

class RenderComponent : public IComponent {
public:

	int height = 0;
	int width = 0;

	AMaterial* material;

	RenderComponent(AObject* parent);
	virtual ~RenderComponent();

	void Update() override;
};
