#pragma once
#include <string>

#include "Util/Singleton.h"

class Window : public Singleton<Window>{

public:
	static const  int WIDTH = 1280;
	static const int HEIGHT = 720;

	std::string assetsFolder;

public:
	Window();

	void Start();
	void Update();
	void End();
	void Excecute();

	void Draw();
	void ProcessFrame(struct GLFWwindow* window);
};
template class Singleton<Window>;
