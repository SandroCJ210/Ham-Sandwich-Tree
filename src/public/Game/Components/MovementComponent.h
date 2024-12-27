#pragma once
#include <glm/glm.hpp>

#include "Core/Components/IComponent.h"


class Rigidbody3DComponent;

class MovementComponent : public IComponent {
private:
	glm::vec2 direction;
	float speed;

	Rigidbody3DComponent* rb;
	
public:
	MovementComponent(AObject* parent);
	~MovementComponent() override;

	void Start() override;
	void Update(double deltaTime) override;

	glm::vec2 GetDirection() const { return direction; }
	double GetSpeed() const { return speed; }

	void SetSpeed(float speed);
	void SetDirection(glm::vec2 direction);
};
