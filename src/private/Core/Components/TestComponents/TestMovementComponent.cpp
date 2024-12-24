#include "Core/Components/TestComponents/TestMovementComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Core/Objects/AObject.h"
#include "Core/Window.h"
#include <iostream>

TestMovementComponent::TestMovementComponent(AObject* parent) : IComponent(parent) {
}

TestMovementComponent::~TestMovementComponent() {
}

void TestMovementComponent::Start() {
	// int size = AObject::FindObjectByName("Maze")->GetComponent<MazeGeneratorComponent>()->GetSize();

	// velocity = Vector3(0.5, 0.5, 0.0);
}

void TestMovementComponent::Update(double deltaTime) {
	
	// this->parent->scale += velocity * deltaTime;
	//
	// if (this->parent->scale.x > 1.2) {
	// 	velocity = velocity * -1;
	// }
	// else if (this->parent->scale.x < 0.001) {
	// 	velocity = velocity * -1;
	// }

	SquareColliderComponent* collider = this->parent->GetComponent<SquareColliderComponent>();
	AObject* player = AObject::FindObjectByName("Player");

	if (Window::GetInstance()
			.GetActualScene()
			->GetPhysicsEngine()
			->PointIntersectsSquareCollider(player->GetWorldPosition(), collider)
		) {
		std::cout << "Collision with " << parent->name <<std::endl;
	}
}

void TestMovementComponent::LateUpdate() {
}