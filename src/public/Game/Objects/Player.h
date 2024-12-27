#pragma once
#include "Core/Objects/AObject.h"

class CameraComponent;
// class RenderQuadComponent;
class InputComponent;
class MovementComponent;
class Rigidbody3DComponent;

class Player : public AObject {
public:
	Player(AObject* parent, std::string name);
	~Player() override;

	void Awake() override;
	
private:

	CameraComponent* playerCamera;
	
	// RenderQuadComponent* renderComponent;
	Rigidbody3DComponent* rigidbodyComponent;
	InputComponent* inputComponent;
	MovementComponent* movementComponent;
	// SquareColliderComponent* colliderComponent;
	
};