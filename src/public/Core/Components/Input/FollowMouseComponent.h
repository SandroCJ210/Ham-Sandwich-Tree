#pragma once
#include <GLFW/glfw3.h>

#include "Core/Components/IComponent.h"

class Vector2;

class FollowMouseComponent : public IComponent {

private:
	Vector2* mousePosition;

public:
	FollowMouseComponent(AObject* parent);
	~FollowMouseComponent() override;
	
	void Update(double deltaTime) override;

private:
	void GetMousePosition();
};
