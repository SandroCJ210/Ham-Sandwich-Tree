#pragma once

class AObject;

class IComponent {
public:
	AObject* parent;
	IComponent() : parent(nullptr) {}
	IComponent(AObject* parent) { this->parent = parent; }
	virtual ~IComponent(){}
	virtual void Start() {}
	virtual void FixedUpdate() {}
	virtual void Update(double deltaTime) {}
	virtual void LateUpdate() {}
	virtual void End() {}
};
