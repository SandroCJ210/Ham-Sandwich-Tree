#include "Core/Scenes/ASceneController.h"
#include "Core/Physics/PhysicsEngine.h"


ASceneController::ASceneController(){
	physicsEngine = new PhysicsEngine();
}

void ASceneController::Start(){
	physicsEngine->Start(objects);

	for (auto element : objects){
		element->Start();
	}
}

void ASceneController::Update(float deltaTime){
	for (auto element : objects){
		element->Update(deltaTime);
	}

	physicsEngine->Update(deltaTime);

	for (auto element : objects) {
		element->LateUpdate();
	}
}

void ASceneController::End(){
	for (auto element : objects){
		element->End();
	}
}
