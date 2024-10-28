#pragma once
#include <vector>

#include "AObject.h"
#include "Util/Singleton.h"

template class Singleton<class SceneController>;
class SceneController : public Singleton<SceneController> {
	
public:
	std::vector<AObject*> objects;
	
	SceneController();

	void Start();
	void Update();
	void End();
};
