#pragma once
#include <glm/glm.hpp>

#include "Core/Components/IComponent.h"

class TestMovementComponent: public IComponent{
public:
	
	glm::vec3 velocity = glm::vec3(0.01, 0.02, 0.0);

	TestMovementComponent(AObject* parent);
	~TestMovementComponent() override;
	void Start() override;
	void Update(double deltaTime) override;
	void LateUpdate() override;
};

