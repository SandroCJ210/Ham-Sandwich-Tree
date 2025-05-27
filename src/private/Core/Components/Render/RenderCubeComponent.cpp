#include "Core/Components/Render/RenderCubeComponent.h"

#include <Core/Materials/LitMaterial.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RenderCubeComponent::RenderCubeComponent(AObject* parent) : IComponent(parent){
	material = new LitMaterial();
}

RenderCubeComponent::~RenderCubeComponent() {
	delete this->material;
}

void RenderCubeComponent::LateUpdate() {
	Draw();
}

void RenderCubeComponent::Draw() {
	if (!enableRender) return;
	
	glm::mat4 model = glm::mat4(1);

	glm::quat rotation = parent->GetWorldRotation();
	glm::vec3 vectorRotation = glm::vec3(rotation.x, rotation.y, rotation.z);
	float angle = 2 * glm::acos(rotation.w);
	model = glm::translate(model, this->parent->GetWorldPosition());
	if (vectorRotation != glm::vec3(0))
		model = glm::rotate(model, angle, vectorRotation);
	
	model = glm::scale(model, this->parent->GetWorldScale());

	Render::GetInstance().DrawCube(model, material);
}