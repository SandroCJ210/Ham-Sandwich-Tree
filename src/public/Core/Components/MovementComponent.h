#pragma once
#include "IComponent.h"
#include "Math/Vector2.h"

class MovementComponent : public IComponent {
private:
	Vector2 direction;
	double speed;
	
public:
	MovementComponent(AObject* parent);
	~MovementComponent() override;

	void Update(float deltaTime) override;

	Vector2 GetDirection() const { return direction; };
	double GetSpeed() const { return speed; };

	void SetSpeed(double speed);
	void SetDirection(Vector2 direction);
};