#pragma once

class AObject;

class IComponent {
public:
	AObject* parent;
	IComponent() = default;
	virtual ~IComponent(){}
	virtual void Update() {}
};
