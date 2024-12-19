#include "Core/Objects/Player.h"

#include "Core/Components/Render/RenderComponent.h"
#include "Core/Components/Input/InputComponent.h"
#include "Core/Components/Maze2D/MazeGeneratorComponent.h"
#include "Core/Components/Maze2D/MovementComponent.h"
#include "Core/Components/Physics/RigidbodyComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Core/Objects/Maze.h"
#include "Core/Materials/BaseMaterial.h"


Player::Player(AObject* parent, std::string name) : AObject(parent, name) {

	renderComponent = dynamic_cast<RenderComponent*>(
		AddComponent(new RenderComponent( this ))
	);
	rigidbodyComponent = dynamic_cast<RigidbodyComponent*>(
		AddComponent(new RigidbodyComponent( this ))
	);
	colliderComponent = dynamic_cast<SquareColliderComponent*>(
		AddComponent(new SquareColliderComponent( this, glm::vec2(0, 0), glm::vec2(0.5, 0.5) ))
	);
	inputComponent = dynamic_cast<InputComponent*>(
		AddComponent(new InputComponent(this))
	);
	movementComponent = dynamic_cast<MovementComponent*>(
		AddComponent(new MovementComponent(this))
	);
	
	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(renderComponent->material);
	baseMaterial->color = glm::vec3(63, 72, 204) / 255.0f;
	
}

void Player::Awake() {
	MazeGeneratorComponent* mazeGenerator =
		AObject::FindObjectByName("Maze")
		->GetComponent<MazeGeneratorComponent>();
	
	float objectQuantity = (float)mazeGenerator->GetSize();
	
	scale = glm::vec3(1.0f / objectQuantity);

	position = glm::vec3(
		-1 + scale.x + scale.x * 2,
		1 - scale.x - scale.x * 2,
		0.0f
	);

	movementComponent->SetSpeed(scale.x * 8);
}

Player::~Player() {
	delete renderComponent;
	delete inputComponent;
	delete movementComponent;
	delete rigidbodyComponent;
	delete colliderComponent;
}