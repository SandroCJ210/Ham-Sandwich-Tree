#pragma once
#include "Core/Objects/AObject.h"

class CameraComponent;
// class RenderQuadComponent;
class InputComponent;
class MovementComponent;
class RigidbodyComponent;

class Player : public AObject {
public:
	Player(AObject* parent, std::string name);
	~Player() override;

	void Awake() override;
	
private:

	CameraComponent* playerCamera;
	
	// RenderQuadComponent* renderComponent;
	RigidbodyComponent* rigidbodyComponent;
	InputComponent* inputComponent;
	MovementComponent* movementComponent;
	// SquareColliderComponent* colliderComponent;
	
};