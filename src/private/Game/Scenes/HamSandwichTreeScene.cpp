#include "Game/Scenes/HamSandwichTreeScene.h"

#include <Game/Objects/HamSandwichTree/Point.h>
#include <Core/Objects/General/CameraObject.h>
#include <Core/Components/Render/CameraComponent.h>
#include <Core/Objects/Light/PointLight.h>
#include <Core/Components/Input/InputComponent.h>
#include <Game/Components/MovementComponent.h>
#include <Core/Components/Physics/3D/Rigidbody3DComponent.h>
#include <Game/Objects/HamSandwichTree/HSTree.h>

HamSandwichTreeScene::HamSandwichTreeScene() {
	bool is3D = false;

	if(is3D){
		SetBasicComponents3D();
	}

	else {
		SetBasicComponents2D();
	}

	HSTree* tree = new HSTree(is3D, 300, 10, "tree", nullptr, this);

}

void HamSandwichTreeScene::SetBasicComponents2D() {
	auto camera = new CameraObject("Camera", nullptr, this);
	camera->position = glm::vec3(0, 0, 10);
	camera->RotateEuler(glm::vec3(0, 0, 0));
	auto cameraComponent = camera->GetCameraComponent();
	cameraComponent->mainCamera = true;
	cameraComponent->orthographic = true;
	cameraComponent->orthoSize = 10.5f;

	auto* lightSource = new PointLight("light", nullptr, this);
	lightSource->scale = glm::vec3(0.1f, 0.1f, 0.1f);
	lightSource->position = glm::vec3(1, 1, -1);
	lightSource->GetComponent<LightComponent>()->SetColor(1, 1, 1);
}

void HamSandwichTreeScene::SetBasicComponents3D() {

	auto camera = new CameraObject("Camera", nullptr, this);
	camera->position = glm::vec3(0, 0, 30);
	camera->RotateEuler(glm::vec3(0, 0, 0));
	auto cameraComponent = camera->GetCameraComponent();
	cameraComponent->mainCamera = true;

	camera->AddComponent(new InputComponent(camera));
	camera->AddComponent(new Rigidbody3DComponent(camera));

	auto movementComponent = dynamic_cast<MovementComponent*>(
		camera->AddComponent(new MovementComponent(camera))
	);
	movementComponent->SetSpeed(6.0f);
	movementComponent->SetRotationSpeed(5.0f);

	auto* lightSource = new PointLight("light", nullptr, this);
	lightSource->scale = glm::vec3(0.1f, 0.1f, 0.1f);
	lightSource->position = glm::vec3(1, 1, -1);
	lightSource->GetComponent<LightComponent>()->SetColor(1, 1, 1);
}
