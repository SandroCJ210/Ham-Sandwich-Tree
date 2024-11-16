#pragma once

class AObject;

class IComponent {
public:
	AObject* parent;
	IComponent() : parent(nullptr) {};
	IComponent(AObject* parent) { this->parent = parent; };
	virtual ~IComponent(){}
	virtual void Update() {}
	virtual void LateUpdate() {}
};
