#include "Core/Objects/SceneController.h"

SceneController::SceneController():Singleton() {
}

void SceneController::Start(){
	for (auto element : objects){
		element->Start();
	}
}

void SceneController::Update(){
	for (auto element : objects){
		element->Update();
	}
	for (auto element : objects) {
		element->LateUpdate();
	}
}

void SceneController::End(){
	for (auto element : objects){
		element->End();
	}
}
