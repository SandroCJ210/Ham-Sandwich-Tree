#include "Core/Components/TestMovementComponent.h"
#include "Core/Objects/AObject.h"

TestMovementComponent::TestMovementComponent(AObject* parent) : IComponent(parent) {
}

TestMovementComponent::~TestMovementComponent() {
}

void TestMovementComponent::Update() {
	
	this->parent->position += velocity*0.01;

	if (this->parent->position.x > 1 || 
		this->parent->position.x < -1 || 
		this->parent->position.y > 1 ||
		this->parent->position.y < -1) {
		velocity *= -1;
	}
}

void TestMovementComponent::LateUpdate() {
}