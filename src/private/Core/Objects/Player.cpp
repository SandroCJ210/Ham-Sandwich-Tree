#include "Core/Objects/Player.h"
#include "Core/Components/RenderComponent.h"
#include "Core/Components/InputComponent.h"
#include "Core/Components/MazeGeneratorComponent.h"
#include "Core/Components/MovementComponent.h"
#include "Core/Components/Physics/RigidbodyComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Core/Objects/Maze.h"
#include "Core/Materials/BaseMaterial.h"


Player::Player(AObject* parent, std::string name, Maze* maze) : AObject(parent, name) {
	this->maze = maze;

	MazeGeneratorComponent* mazeGenerator = maze->GetMazeGeneratorComponent();

	renderComponent = dynamic_cast<RenderComponent*>(AddComponent(new RenderComponent(this)));
	rigidbodyComponent = dynamic_cast<RigidbodyComponent*>(AddComponent(new RigidbodyComponent(this)));
	colliderComponent = dynamic_cast<SquareColliderComponent*>(AddComponent(new SquareColliderComponent(this)));
	inputComponent = dynamic_cast<InputComponent*>(AddComponent(new InputComponent(this)));
	movementComponent = dynamic_cast<MovementComponent*>(AddComponent(new MovementComponent(this)));

	int objectQuantity = mazeGenerator->GetSize();
	float objectScale = (2.0 / objectQuantity) / 2;

	renderComponent->SetScale(Vector3(objectScale));

	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(renderComponent->material);
	baseMaterial->color = Vector3(63, 72, 204)/255;

	position = Vector3(
		-1 + objectScale + objectScale * 2,
		1 - objectScale - objectScale * 2,
		0.0f);
	
	colliderComponent->center = Vector2(0, 0);
	colliderComponent->halfSize = Vector2(objectScale/2, objectScale/2);

	movementComponent->SetSpeed(objectScale * 8);
}	

Player::~Player() {
	delete renderComponent;
	delete inputComponent;
	delete movementComponent;
	delete rigidbodyComponent;
	delete colliderComponent;
}