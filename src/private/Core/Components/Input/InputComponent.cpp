#include "Core/Components/Input/InputComponent.h"

#include "Core/Components/Maze2D/MovementComponent.h"
#include "Core/Objects/AObject.h"

InputComponent::InputComponent(AObject* parent) : IComponent(parent) {
}

InputComponent::~InputComponent() {
}

void InputComponent::Update(double deltaTime) {
	SetMovementDirection();
}

void InputComponent::SetMovementDirection() {
	Vector2 direction = Vector2::zero;

	if (glfwGetKey(glfwGetCurrentContext(), UP) == GLFW_PRESS) {
		direction.y = 1;
	}
	if (glfwGetKey(glfwGetCurrentContext(), DOWN) == GLFW_PRESS) {
		direction.y = -1;
	}
	if (glfwGetKey(glfwGetCurrentContext(), LEFT) == GLFW_PRESS) {
		direction.x = -1;
	}
	if (glfwGetKey(glfwGetCurrentContext(), RIGHT) == GLFW_PRESS) {
		direction.x = 1;
	}

	MovementComponent* movement = parent->GetComponent<MovementComponent>();

	if (movement != nullptr)
		movement->SetDirection(direction);
}