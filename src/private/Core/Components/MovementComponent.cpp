#include "Core/Components/MovementComponent.h"
#include "Core/Components/Physics/RigidBodyComponent.h"
#include "Core/Objects/AObject.h"

MovementComponent::MovementComponent(AObject* parent) : IComponent(parent) {
	direction = Vector2(0, 0);
	speed = 0;
}

MovementComponent::~MovementComponent() {
}

void MovementComponent::Update(float deltaTime) {
	parent->GetComponent<RigidbodyComponent>()->velocity = direction * speed;
}

void MovementComponent::SetSpeed(double speed) {
	this->speed = speed;
}

void MovementComponent::SetDirection(Vector2 direction) {
	this->direction = direction;
}