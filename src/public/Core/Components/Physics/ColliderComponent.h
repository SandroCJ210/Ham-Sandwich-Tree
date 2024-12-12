#pragma once
#include "Core/Components/IComponent.h"
#include "Math/Vector2.h"

class ColliderComponent : public IComponent {
public:
	bool isTrigger = false;

	ColliderComponent(AObject* parent);
};