#pragma once
#include <string>

#include "Util/Singleton.h"
#include "Core/Scenes/ASceneController.h"

class Window : public Singleton<Window>{

private:
	ASceneController* actualScene;

public:
	Window();
	void Excecute();
	void AddObjectToScene(AObject* object);

private:
	void Start();
	void Update();
	void End();
	void ProcessFrame(struct GLFWwindow* window);

public:
	void SetActualScene(ASceneController* scene) { actualScene = scene; }
	
	ASceneController* GetActualScene() const { return actualScene; }
};
template class Singleton<Window>;
