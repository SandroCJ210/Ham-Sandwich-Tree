#pragma once
#include "Core/Components/IComponent.h"

class AColliderComponent : public IComponent {
public:
	bool isTrigger = false;

	AColliderComponent(AObject* parent)
		: IComponent(parent) {}
};
