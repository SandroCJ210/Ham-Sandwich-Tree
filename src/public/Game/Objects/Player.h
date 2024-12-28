#pragma once
#include "Core/Objects/AObject.h"

class CameraComponent;
class InputComponent;
class MovementComponent;
class Rigidbody3DComponent;
class BoxColliderComponent;

class Player : public AObject {
public:
	Player(AObject* parent, std::string name);
	~Player() override;

	void Awake() override;
	
private:

	CameraComponent* playerCamera;

	Rigidbody3DComponent* rigidbodyComponent;
	InputComponent* inputComponent;
	MovementComponent* movementComponent;
	BoxColliderComponent* colliderComponent;
	
};