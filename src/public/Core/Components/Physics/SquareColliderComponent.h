#pragma once
#include "Core/Components/Physics/ColliderComponent.h"
#include "Math/Vector2.h"

class AObject;

class SquareColliderComponent : public ColliderComponent {
public:
	Vector2 center;
	Vector2 halfSize;

	SquareColliderComponent(AObject* parent);
	SquareColliderComponent(AObject* parent, Vector2 center, Vector2 halfSize);
	~SquareColliderComponent();
};