#include "Core/Components/Maze2D/MovementComponent.h"

#include <iostream>

#include "Core/Components/Physics/RigidBodyComponent.h"
#include "Math/Vector2.h"
#include "Core/Objects/AObject.h"

MovementComponent::MovementComponent(AObject* parent) : IComponent(parent) {
	direction = Vector2(-1, 0);
	speed = 0;
}

MovementComponent::~MovementComponent() {
}

void MovementComponent::Update(double deltaTime) {
	Vector2 normalizeDirection =  direction.Normalize();
	parent->GetComponent<RigidbodyComponent>()->velocity = normalizeDirection * speed;
}

void MovementComponent::SetSpeed(double speed) {
	this->speed = speed;
}

void MovementComponent::SetDirection(Vector2 direction) {
	this->direction = direction;
}