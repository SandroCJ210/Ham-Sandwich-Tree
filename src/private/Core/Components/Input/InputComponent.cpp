#include "Core/Components/Input/InputComponent.h"

#include "Game/Components/MovementComponent.h"
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
	glm::vec2 direction = glm::vec2(0);

	//WASD
	if (glfwGetKey(glfwGetCurrentContext(), UP) == GLFW_PRESS) {
		direction += glm::vec2(0, 1);
	}
	if (glfwGetKey(glfwGetCurrentContext(), DOWN) == GLFW_PRESS) {
		direction += glm::vec2(0, -1);
	}
	if (glfwGetKey(glfwGetCurrentContext(), LEFT) == GLFW_PRESS) {
		direction += glm::vec2(-1, 0);
	}
	if (glfwGetKey(glfwGetCurrentContext(), RIGHT) == GLFW_PRESS) {
		direction += glm::vec2(1, 0);
	}

	//Rotation to Right-Left (Q-E)
	glm::vec2 rotation = glm::vec2(0);
	if (glfwGetKey(glfwGetCurrentContext(), RIGHT_ROTATION) == GLFW_PRESS) {
		rotation.x += 1;
	}
	if (glfwGetKey(glfwGetCurrentContext(), LEFT_ROTATION) == GLFW_PRESS) {
		rotation.x -= 1;
	}
	if (glfwGetKey(glfwGetCurrentContext(), UP_ROTATION) == GLFW_PRESS) {
		rotation.y += 1;
	}
	if (glfwGetKey(glfwGetCurrentContext(), DOWN_ROTATION) == GLFW_PRESS) {
		rotation.y -= 1;
	}

	if (movementComponent != nullptr) {
		movementComponent->SetDirection(direction);
		movementComponent->SetRotation(rotation);
	}
		
}