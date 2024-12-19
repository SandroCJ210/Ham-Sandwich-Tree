#pragma once
#include "Core/Components/IComponent.h"

class ColliderComponent : public IComponent {
public:
	bool isTrigger = false;

	ColliderComponent(AObject* parent);
};