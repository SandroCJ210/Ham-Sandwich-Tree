#pragma once
#include <string>

#include "Util/Singleton.h"
#include "Core/Scenes/ASceneController.h"

class Window : public Singleton<Window>{

public:

	ASceneController* actualScene;

public:
	Window();

	void Start();
	void Update();
	void End();
	void Excecute();

	void ProcessFrame(struct GLFWwindow* window);
};
template class Singleton<Window>;
