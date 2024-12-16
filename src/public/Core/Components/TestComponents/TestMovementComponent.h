#pragma once
#include "Core/Components/IComponent.h"
#include "Math/Vector3.h"

class TestMovementComponent: public IComponent{
public:
	
	Vector3 velocity = Vector3(0.01, 0.02, 0.0);

	TestMovementComponent(AObject* parent);
	~TestMovementComponent() override;
	void Start() override;
	void Update(double deltaTime) override;
	void LateUpdate() override;
};

