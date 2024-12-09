#pragma once
#include <GLFW/glfw3.h>
#include "Core/Components/IComponent.h"
#include "Math/Vector2.h"

class InputComponent : public IComponent {

private:
	Vector2 direction;

private:
	const int UP = GLFW_KEY_W;
	const int DOWN = GLFW_KEY_S;
	const int LEFT = GLFW_KEY_A;
	const int RIGHT = GLFW_KEY_D;

public:
	InputComponent(AObject* parent);
	~InputComponent() override;

	void Update(float deltaTime) override;

private:
	void SetMovementDirection();
};