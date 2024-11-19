#include "Core/Scenes/ASceneController.h"

ASceneController::ASceneController(){
}

void ASceneController::Start(){
	for (auto element : objects){
		element->Start();
	}
}

void ASceneController::Update(){
	for (auto element : objects){
		element->Update();
	}
	for (auto element : objects) {
		element->LateUpdate();
	}
}

void ASceneController::End(){
	for (auto element : objects){
		element->End();
	}
}
