#pragma once
#include <vector>

#include "Core/Objects/AObject.h"


class ASceneController {
	
public:
	std::vector<AObject*> objects;
	
	ASceneController();

	virtual void Start();
	virtual void Update();
	virtual void End();
};