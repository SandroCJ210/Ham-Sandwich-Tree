#include "Core/Components/TestMovementComponent.h"
#include "Core/Components/MazeGeneratorComponent.h"
#include "Core/Objects/AObject.h"

TestMovementComponent::TestMovementComponent(AObject* parent) : IComponent(parent) {
}

TestMovementComponent::~TestMovementComponent() {
}

void TestMovementComponent::Start() {
	int size = AObject::FindObjectByName("Maze")->GetComponent<MazeGeneratorComponent>()->GetSize();

	velocity = Vector3(0.01 / size, 0.02 / size, 0.0);
}

void TestMovementComponent::Update(float deltaTime) {
	
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