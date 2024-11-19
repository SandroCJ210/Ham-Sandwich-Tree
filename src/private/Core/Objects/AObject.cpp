#include "Core/Objects/AObject.h"

AObject::AObject(AObject* _parent) {
	this->parent = _parent;
	if (parent == nullptr) return;
	_parent->children.push_back(this);
}

AObject::~AObject() {
}

void AObject::Start() {
	for (auto element : components) {
		element->Start();
	}
	for (auto element : children) {
		element->Start();
	}
}

void AObject::Update() {
	for (auto element : components) {
		element->Update();
	}
	for (auto element : children) {
		element->Update();
	}
}

void AObject::LateUpdate() {
	for (auto element : components) {
		element->LateUpdate();
	}
	for (auto element : children) {
		element->LateUpdate();
	}
}

void AObject::End() {
	for (auto element : components) {
		delete element;
	}
	for (auto element : children) {
		delete element;
	}
}

IComponent* AObject::AddComponent(IComponent* component) {
	components.push_back(component);
	return component;
}

void AObject::AddChild(AObject* child) {
	children.push_back(child);
}



