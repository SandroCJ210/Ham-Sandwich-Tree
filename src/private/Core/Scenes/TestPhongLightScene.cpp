#include <Core/Components/Render/CameraComponent.h>
#include <Core/Scenes/TestPhongLightScene.h>

#include <Core/Materials/LitMaterial.h>
#include <Core/Objects/3D/Cube.h>
#include <Core/Components/Render/RenderCubeComponent.h>
#include <Core/Objects/Light/PointLight.h>

TestPhongLightScene::TestPhongLightScene() {

	auto* cameraObject = new EmptyObject(nullptr, "Camera");
	auto* cameraComponent = dynamic_cast<CameraComponent*>(
		cameraObject->AddComponent(new CameraComponent(cameraObject))
		);
	cameraObject->position = glm::vec3(0, 0, 10);
	cameraComponent->orthographic = true;
	cameraComponent->mainCamera = true;
	cameraComponent->orthoSize = 2.0f;
	AddObject(cameraObject);

	auto* cube = new Cube(nullptr, "Square2");
	cube->scale = glm::vec3(1, 1, 1);
	cube->position = glm::vec3(0, 0, 0);
	dynamic_cast<LitMaterial*>(cube->GetRenderComponent()->material)
		->SetColor(glm::vec3(1, 0.5, 1))
		->SetTexture("Assets/Textures/HL.jpg");

	auto* lightSource = new PointLight(nullptr, "light");
	lightSource->scale = glm::vec3(0.1f, 0.1f, 0.1f);
	lightSource->position = glm::vec3(1, 1, 1);
	lightSource->AddComponent(new RenderCubeComponent(lightSource));

}
