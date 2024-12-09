#include "Core/Components/Physics/SquareColliderComponent.h"

SquareColliderComponent::SquareColliderComponent(AObject* parent) : ColliderComponent(parent) {
	center = Vector2(0, 0);
	halfSize = Vector2(0, 0);
}

SquareColliderComponent::SquareColliderComponent(AObject* parent, Vector2 center, Vector2 halfSize) : SquareColliderComponent(parent) {
	this->center = center;
	this->halfSize = halfSize;
}

SquareColliderComponent::~SquareColliderComponent() {
}