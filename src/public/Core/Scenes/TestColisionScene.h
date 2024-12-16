#pragma once
#include "ASceneController.h"

class TestColisionScene : public ASceneController{
public:
	TestColisionScene();
	
	void Update(double deltaTime) override;
};
