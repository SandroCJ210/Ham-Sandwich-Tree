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

void InputComponent::Start() {
	movementComponent = parent->GetComponent<MovementComponent>();
}

void InputComponent::SetMovementDirection() {
	Vector2 direction = Vector2::zero;

	if (glfwGetKey(glfwGetCurrentContext(), UP) == GLFW_PRESS) {
		direction += Vector2(0, 1);
	}
	if (glfwGetKey(glfwGetCurrentContext(), DOWN) == GLFW_PRESS) {
		direction += Vector2(0, -1);
	}
	if (glfwGetKey(glfwGetCurrentContext(), LEFT) == GLFW_PRESS) {
		direction += Vector2(-1, 0);
	}
	if (glfwGetKey(glfwGetCurrentContext(), RIGHT) == GLFW_PRESS) {
		direction += Vector2(1, 0);
	}

	if (movementComponent != nullptr)
		movementComponent->SetDirection(direction);
}