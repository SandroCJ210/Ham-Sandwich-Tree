#include "Core/Scenes/ASceneController.h"

#include <iostream>
#include <GLFW/glfw3.h>

#include "Core/Global.h"
#include "Core/Physics/PhysicsEngine.h"


ASceneController::ASceneController(){
	physicsEngine = new PhysicsEngine();
}

ASceneController::~ASceneController(){
	delete physicsEngine;
}

void ASceneController::AddObject(AObject* object){
	objects.push_back(object);
}

void ASceneController::Awake(){
	previous = glfwGetTime();
	
	for (auto element : objects){
		if (!element->isEnabled) continue;
		element->Awake();
	}
}

void ASceneController::Start(){
	for (auto element : objects){
		if (!element->isEnabled) continue;
		element->Start();
	}
	physicsEngine->Start(objects);

}

void ASceneController::SceneUpdate(){
	current = glfwGetTime();
	double deltaTime = current - previous;
	previous = current;
	physicsTimeOffset += deltaTime;

	// double fps = 1.0 / deltaTime;
	// std::cout<<"FPS: "<<fps<<std::endl;
	
	while (physicsTimeOffset >= Global::FIXED_DELTA_TIME){
		FixedUpdate();
		physicsTimeOffset -= Global::FIXED_DELTA_TIME;
		if (Global::DEBUG)
			physicsTimeOffset = 0;
	}

	Update(deltaTime);
	LateUpdate();
}

void ASceneController::FixedUpdate() {
	for (auto element : objects) {
		if (!element->isEnabled) continue;
		element->FixedUpdate();
	}
	physicsEngine->Update();
}

void ASceneController::Update(double deltaTime){
	for (auto element : objects){
		if (!element->isEnabled) continue;
		element->Update(deltaTime);
	}
}

void ASceneController::LateUpdate(){
	for (auto element : objects){
		if (!element->isEnabled) continue;
		element->LateUpdate();
	}
}

void ASceneController::End(){
	for (auto element : objects){
		element->End();
	}
}
