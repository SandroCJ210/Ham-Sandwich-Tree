#include "Core/Components/Physics/SquareColliderComponent.h"

#include "Core/Global.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Color.h"
#include "Core/Render/Render.h"

SquareColliderComponent::SquareColliderComponent(AObject* parent) : ColliderComponent(parent) {
	center = glm::vec2(0.0);
	halfSize = glm::vec2(0.0);
}

SquareColliderComponent::SquareColliderComponent(AObject* parent, glm::vec2 center,
												glm::vec2 halfSize) : SquareColliderComponent(parent) {
	this->center = center;
	this->halfSize = halfSize;
}

SquareColliderComponent::~SquareColliderComponent() {
}

void SquareColliderComponent::FixedUpdate() {
	worldCenter = parent->GetGlobalPosition() + glm::vec3(center, 0) ;

	worldHalfSize = glm::vec2(
		halfSize.x * parent->GetGlobalScale().x,
		halfSize.y * parent->GetGlobalScale().y
	);
}

void SquareColliderComponent::Update(double deltatime) {
}

void SquareColliderComponent::LateUpdate() {
	if (Global::DEBUG) {
		Render::GetInstance().DrawQuadLine(
			glm::vec3(worldCenter, 0.0),
			glm::vec3(worldHalfSize, 0) * 2.0f,
			Color::GREEN);
	}
}