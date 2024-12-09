#pragma once
#include "Core/Objects/AObject.h"

class Maze;
class RenderComponent;
class InputComponent;
class MovementComponent;
class RigidbodyComponent;
class SquareColliderComponent;

class Player : public AObject {
public:
	Player(AObject* parent, std::string name, Maze* maze);
	~Player() override;

private:
	Maze* maze;

	RenderComponent* renderComponent;
	RigidbodyComponent* rigidbodyComponent;
	InputComponent* inputComponent;
	MovementComponent* movementComponent;
	SquareColliderComponent* colliderComponent;
	
};