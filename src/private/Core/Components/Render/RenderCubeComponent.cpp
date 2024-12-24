#include "Core/Components/Render/RenderCubeComponent.h"

#include "Core/Materials/BaseMaterial.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RenderCubeComponent::RenderCubeComponent(AObject* parent) : IComponent(parent){
	material = new BaseMaterial();
	
	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(material);
}

RenderCubeComponent::~RenderCubeComponent() {
	delete this->material;
}

void RenderCubeComponent::LateUpdate() {
	Draw();
}

void RenderCubeComponent::Draw() {
	if (!enableRender) return;

	glm::vec3 center = this->parent->GetWorldPosition();
	glm::vec3 scale = this->parent->GetWorldScale();

	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(material);

	Render::GetInstance().DrawCube(center, scale, material->shader, baseMaterial->color);
}