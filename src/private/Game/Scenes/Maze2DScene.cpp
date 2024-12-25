#include "Game/Scenes/Maze2DScene.h"

#include "Core/Components/Render/CameraComponent.h"
#include "Core/Objects/EmptyObject.h"
#include "Core/Objects/SquareObject.h"
#include "Game/Objects/Maze.h"
#include "Game/Objects/Player.h"

Maze2DScene::Maze2DScene() {

	EmptyObject* cameraObject = new EmptyObject(nullptr, "Camera");
	CameraComponent* cameraComponent = dynamic_cast<CameraComponent*>(
		cameraObject->AddComponent(new CameraComponent(cameraObject))
		);
	cameraComponent->orthographic = true;
	cameraComponent->mainCamera = true;
	cameraComponent->orthoSize = 1.0f;
	cameraObject->position = glm::vec3(0, 0, 3);
	AddObject(cameraObject);

	Maze* maze = new Maze(nullptr, "Maze");
	AddObject(maze);
	
	Player* player = new Player(nullptr, "Player");
	AddObject(player);
}