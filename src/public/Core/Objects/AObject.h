#pragma once
#include <vector>

#include "Core/Components/IComponent.h"
#include "Math/Vector3.h"


class AObject {
public:
	Vector3 position = {0, 0, 0}; //this is the position from the center
	Vector3 rotation = {0, 0, 0}; //this will change in the future
	std::vector<IComponent*> components;

	AObject* parent = nullptr;
	std::vector<AObject*> children;
	
	AObject();
	~AObject();
	
	virtual void Start();
	virtual void Update();
	virtual void End();

	void addComponent(IComponent* component);
};
