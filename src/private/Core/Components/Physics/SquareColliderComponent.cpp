#include "Core/Components/Physics/SquareColliderComponent.h"

#include "Core/Global.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"
#include "Math/Vector2.h"

SquareColliderComponent::SquareColliderComponent(AObject* parent) : ColliderComponent(parent) {
	center = Vector2(0, 0);
	halfSize = Vector2(0, 0);
}

SquareColliderComponent::SquareColliderComponent(AObject* parent, Vector2 center,
												Vector2 halfSize) : SquareColliderComponent(parent) {
	this->center = center;
	this->halfSize = halfSize;
}

SquareColliderComponent::~SquareColliderComponent() {
}

void SquareColliderComponent::Update(float deltatime) {
	worldCenter = parent->GetGlobalPosition() + center;

	worldHalfSize = Vector2(
		halfSize.x * parent->GetGlobalScale().x,
		halfSize.y * parent->GetGlobalScale().y
	);
}

void SquareColliderComponent::LateUpdate() {
	if (Global::DEBUG) {
		Render::GetInstance().DrawQuadLine(worldCenter, worldHalfSize * 2);
	}
}

Vector2 SquareColliderComponent::GetMin() {
	return worldCenter - worldHalfSize;
}

Vector2 SquareColliderComponent::GetMax() {
	return worldCenter + worldHalfSize;
}