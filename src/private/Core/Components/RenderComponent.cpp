#include "Core/Components/RenderComponent.h"

#include "Core/Materials/BaseMaterial.h"

RenderComponent::RenderComponent(AObject* newParent) {
	//this->parent = newParent;
	this->material = new BaseMaterial();
}

RenderComponent::~RenderComponent() {
	delete this->material;
}

void RenderComponent::Update() {
	
}

