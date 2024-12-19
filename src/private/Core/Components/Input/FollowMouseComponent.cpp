#include "Core/Components/Input/FollowMouseComponent.h"

#include <iostream>
#include <GLFW/glfw3.h>

#include "Core/Global.h"
#include "Core/Objects/AObject.h"

FollowMouseComponent::FollowMouseComponent(AObject* parent) : IComponent(parent) {
	mousePosition = glm::vec2();
}

FollowMouseComponent::~FollowMouseComponent() {
	delete &mousePosition;
}


void FollowMouseComponent::Update(double deltaTime) {
	GetMousePosition();
	parent->position = glm::vec3(mousePosition.x, mousePosition.y, 0);
}

void FollowMouseComponent::GetMousePosition() {
	double x, y;
	glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);
	mousePosition.x = ((2 * x / Global::SCREEN_WIDTH) - 1) * Global::SCREEN_FORMAT / Global::METER;
	mousePosition.y = (1 - (2 * y/ Global::SCREEN_HEIGHT))/ Global::METER;
}