#pragma once
#include <string>

#include "Util/Singleton.h"
#include "Materials/AMaterial.h"

class Window : public Singleton<Window>{

public:
	static const  int WIDTH = 720;
	static const int HEIGHT = 720;

	std::string assetsFolder;

	AMaterial* material;

public:
	Window();

	void Start();
	void Update();
	void End();
	void Excecute();

	void ProcessFrame(struct GLFWwindow* window);
};
template class Singleton<Window>;
