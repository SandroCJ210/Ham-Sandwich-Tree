#include <string>

#include "Core/Scenes/ASceneController.h"
#include "Core/Window.h"
#include "Core/Objects/AObject.h"

AObject::AObject(AObject* _parent, std::string name) {
	this->parent = _parent;
	this->name = name;
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

void AObject::Update(float deltaTime) {
	for (auto element : components) {
		element->Update(deltaTime);
	}
	for (auto element : children) {
		element->Update(deltaTime);
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

AObject* AObject::FindObjectByName(std::string name) {
	
	ASceneController* scene = Window::GetInstance().actualScene;

	for (AObject* object : scene->objects) {
		if (object->name == name) {
			return object;
		}
	}
}



