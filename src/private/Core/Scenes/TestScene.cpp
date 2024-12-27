#include "Core/Scenes/TestScene.h"

#include "Core/Components/Physics/2D/SquareColliderComponent.h"
#include "Core/Components/Render/CameraComponent.h"
#include "Core/Components/Render/RenderQuadComponent.h"
#include "Core/Objects/SquareObject.h"
#include "Game/Objects/Player.h"
#include "Core/Materials/TextureMaterial.h"
#include "Core/Materials/ColorMaterial.h"
#include "Core/Objects/CubeObject.h"
#include "Core/Objects/EmptyObject.h"
#include "Core/Render/Render.h"

TestScene::TestScene() {
	// Player* square = new Player(nullptr, "Square");
	/*square->scale =Vector3(0.5, 0.5, 0.5);
	square->position = Vector3(-1, -1, 0);*/
	
	// objects.push_back(square);

	SquareObject* square2 = new SquareObject(nullptr, "Square2");
	square2->scale = glm::vec3(1, 1, 1);
	square2->position = glm::vec3(0, 0, 0);
	dynamic_cast<TextureMaterial*>(square2->GetRenderComponent()->material)
		->SetTexture("Assets/Textures/HL.jpg");
	
	AddObject(square2);

	EmptyObject* cameraObject = new EmptyObject(nullptr, "Camera");
	CameraComponent* cameraComponent = dynamic_cast<CameraComponent*>(
		cameraObject->AddComponent(new CameraComponent(cameraObject))
		);
	cameraObject->position = glm::vec3(0, 0, 10);
	cameraComponent->orthographic = true;
	cameraComponent->mainCamera = true;
	cameraComponent->orthoSize = 2.0f;
	AddObject(cameraObject);

	// CubeObject* cube = new CubeObject(nullptr, "Cube");
	// cube->scale = glm::vec3(1, 1, 1);
	// cube->position = glm::vec3(2, 2, 0);
	// AddObject(cube);
	
	// SquareObject* square1 = new SquareObject(nullptr, "Square2");
	// square1->scale = glm::vec3(0.5, 0.5, 0.5);
	// square1->position = glm::vec3(0, 1.0f, 0);
	// AddObject(square1);
	//
	// SquareObject* square3 = new SquareObject(nullptr, "Square2");
	// square3->scale = glm::vec3(0.5, 0.5, 0.5);
	// square3->position = glm::vec3(2.0f, 0, 0);
	// AddObject(square3);
}
