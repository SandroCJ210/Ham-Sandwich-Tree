#include <string>
#include "Core/Scenes/ASceneController.h"
#include "Core/Window.h"
#include "Core/Objects/AObject.h"

#include <iostream>

#include "Math/Transformation.h"

AObject::AObject(AObject* _parent, std::string name) {
	this->parent = _parent;
	this->name = name;
	if (parent == nullptr) return;
	parent->AddChild(this);
}

AObject::~AObject() {
}

void AObject::Awake() {
	for (auto element : components) {
		if (!element->isEnabled) continue;
		element->Awake();
	}
	for (auto element : children) {
		if (!element->isEnabled) continue;
		element->Awake();
	}
}

void AObject::Start() {
	for (auto element : components) {
		if (!element->isEnabled) continue;
		element->Start();
	}
	for (auto element : children) {
		if (!element->isEnabled) continue;
		element->Start();
	}
}

void AObject::FixedUpdate() {
	if (parent != nullptr) {

		globalScale = Vector3(
			scale.x * parent->globalScale.x,
			scale.y * parent->globalScale.y,
			scale.z * parent->globalScale.z
		);

		globalPosition = parent->globalPosition + Vector3(
			position.x * parent->globalScale.x,
			position.y * parent->globalScale.y,
			position.z * parent->globalScale.z
		);

	}
	else {
		this->globalScale = scale;
		this->globalPosition = position;
	}

	for (auto element : components) {
		if (!element->isEnabled) continue;
		element->FixedUpdate();
	}

	for (auto element : children) {
		if (!element->isEnabled) continue;
		element->FixedUpdate();
	}
}


void AObject::Update(double deltaTime) {

	for (auto element : components) {
		if (!element->isEnabled) continue;
		element->Update(deltaTime);
	}

	for (auto element : children) {
		if (!element->isEnabled) continue;
		element->Update(deltaTime);
	}
}

void AObject::LateUpdate() {
	for (auto element : components) {
		if (!element->isEnabled) continue;
		element->LateUpdate();
	}
	for (auto element : children) {
		if (!element->isEnabled) continue;
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
	
	ASceneController* scene = Window::GetInstance().GetActualScene();

	for (AObject* object : scene->objects) {
		if (object->name == name) {
			return object;
		}
	}
	return nullptr;
}

void AObject::SetGlobalPosition(Vector3 position) {
	if (parent != nullptr) {
		this->position = Vector3(
			(position.x - parent->globalPosition.x) / parent->globalScale.x,
			(position.y - parent->globalPosition.y) / parent->globalScale.y,
			(position.z - parent->globalPosition.z) / parent->globalScale.z
		);
	}
	else {
		this->position = position;
	}
	this->globalPosition = position;
}

void AObject::SetGlobalRotation(Vector3 rotation) {
}

void AObject::SetGlobalScale(Vector3 scale) {
	if (parent != nullptr) {
		this->scale = Vector3(
			scale.x / parent->globalScale.x,
			scale.y / parent->globalScale.y,
			scale.z / parent->globalScale.z
		);
	}
	else {
		this->scale = scale;
	}
	this->scale = scale;
}


