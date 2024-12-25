#include "Game/Components/MovementComponent.h"

#include <iostream>

#include "Core/Components/Physics/RigidBodyComponent.h"
#include "Core/Objects/AObject.h"
#include "Util/Logger.h"

MovementComponent::MovementComponent(AObject* parent) : IComponent(parent) {
	direction = glm::vec2(0, 0);
	speed = 0;
}

MovementComponent::~MovementComponent() {
}

void MovementComponent::Start() {
	rb = parent->GetComponent<RigidbodyComponent>();
	if (rb == nullptr) {
		Logger::Error("MovementComponent::Start -> RigidbodyComponent not found");
	}
}

void MovementComponent::Update(double deltaTime) {
	glm::vec2 normalizeDirection =  direction != glm::vec2(0)? glm::normalize(direction) : direction;
	glm::vec3 velocity = glm::vec3(normalizeDirection, 0) * speed;
	rb->velocity = velocity;
}

void MovementComponent::SetSpeed(float speed) {
	this->speed = speed;
}

void MovementComponent::SetDirection(glm::vec2 direction) {
	this->direction = direction;
}