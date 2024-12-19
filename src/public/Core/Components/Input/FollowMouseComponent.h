#pragma once
#include <glm/glm.hpp>

#include "Core/Components/IComponent.h"

class FollowMouseComponent : public IComponent {

private:
	glm::vec2 mousePosition;

public:
	FollowMouseComponent(AObject* parent);
	~FollowMouseComponent() override;
	
	void Update(double deltaTime) override;

private:
	void GetMousePosition();
};
