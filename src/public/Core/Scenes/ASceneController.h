#pragma once
#include <vector>
#include "Core/Physics/PhysicsEngine.h"
#include "Core/Objects/AObject.h"

class ASceneController {

private:
	PhysicsEngine* physicsEngine;
	
public:
	std::vector<AObject*> objects;
	
	ASceneController();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void End();

	PhysicsEngine* GetPhysicsEngine() const { return physicsEngine; }
};