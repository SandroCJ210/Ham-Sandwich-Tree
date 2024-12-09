#include "Core/Components/InputComponent.h"
#include "Core/Components/MovementComponent.h"
#include "Core/Objects/AObject.h"

InputComponent::InputComponent(AObject* parent) : IComponent(parent) {
}

InputComponent::~InputComponent() {
}

void InputComponent::Update(float deltaTime) {
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

	parent->GetComponent<MovementComponent>()->SetDirection(direction);
}