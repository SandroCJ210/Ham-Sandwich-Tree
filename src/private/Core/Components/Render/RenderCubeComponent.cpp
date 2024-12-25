#include "Core/Components/Render/RenderCubeComponent.h"

#include "Core/Materials/TextureMaterial.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RenderCubeComponent::RenderCubeComponent(AObject* parent) : IComponent(parent){
	material = new TextureMaterial();
	
	TextureMaterial* baseMaterial = dynamic_cast<TextureMaterial*>(material);
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

	TextureMaterial* baseMaterial = dynamic_cast<TextureMaterial*>(material);

	Render::GetInstance().DrawCube(center, scale, material->shader, baseMaterial->color);
}