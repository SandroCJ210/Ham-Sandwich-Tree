#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Core/Components/IComponent.h"

class MovementComponent;
class InputComponent : public IComponent {

private:
	glm::vec2 direction;

private:
	const int UP = GLFW_KEY_W;
	const int DOWN = GLFW_KEY_S;
	const int LEFT = GLFW_KEY_A;
	const int RIGHT = GLFW_KEY_D;

	MovementComponent* movementComponent;

public:
	InputComponent(AObject* parent);
	~InputComponent() override;

	void Start() override;
	void Update(double deltaTime) override;

private:
	void SetMovementDirection();
};