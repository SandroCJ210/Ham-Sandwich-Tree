#include "Game/Objects/Player.h"

#include "Core/Components/Render/RenderQuadComponent.h"
#include "Core/Components/Input/InputComponent.h"
#include "Game/Components/MazeGeneratorComponent.h"
#include "Game/Components/MovementComponent.h"
#include "Core/Components/Physics/3D/Rigidbody3DComponent.h"
#include "Core/Components/Render/CameraComponent.h"
#include "Game/Objects/Maze.h"


Player::Player(AObject* parent, std::string name) : AObject(parent, name) {

	playerCamera = dynamic_cast<CameraComponent*>(
		AddComponent(new CameraComponent(this))
	);
	playerCamera->orthographic = false;
	playerCamera->mainCamera = true;
	playerCamera->FOV = 60.0f;
	
	// renderComponent = dynamic_cast<RenderQuadComponent*>(
	// 	AddComponent(new RenderQuadComponent( this ))
	// );
	rigidbodyComponent = dynamic_cast<Rigidbody3DComponent*>(
		AddComponent(new Rigidbody3DComponent( this ))
	);
	// colliderComponent = dynamic_cast<SquareColliderComponent*>(
	// 	AddComponent(new SquareColliderComponent( this, glm::vec2(0, 0), glm::vec2(0.5, 0.5) ))
	// );
	inputComponent = dynamic_cast<InputComponent*>(
		AddComponent(new InputComponent(this))
	);
	movementComponent = dynamic_cast<MovementComponent*>(
		AddComponent(new MovementComponent(this))
	);
	
	// TextureMaterial* baseMaterial = dynamic_cast<TextureMaterial*>(renderComponent->material);
	// baseMaterial->color = glm::vec3(63, 72, 204) / 255.0f;
	
}

void Player::Awake() {
	// MazeGeneratorComponent* mazeGenerator =
	// 	AObject::FindObjectByName("Maze")
	// 	->GetComponent<MazeGeneratorComponent>();
	
	// float objectQuantity = (float)mazeGenerator->GetSize();
	
	// scale = glm::vec3(1.0f / objectQuantity);
	position = glm::vec3(0.0f, 1.5f, -5.0f);
	// position = glm::vec3(
	// 	-1 + scale.x + scale.x * 2,
	// 	1 - scale.x - scale.x * 2,
	// 	0.0f
	// );

	movementComponent->SetSpeed(1.0f);

	AObject::Awake();
}

Player::~Player() {
	delete playerCamera;
	// delete renderComponent;
	// delete inputComponent;
	// delete movementComponent;
	// delete rigidbodyComponent;
	// delete colliderComponent;
}