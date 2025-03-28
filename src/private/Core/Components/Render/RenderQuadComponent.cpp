#include "Core/Components/Render/RenderQuadComponent.h"

#include <Core/Materials/LitMaterial.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Core/Render/Shader.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RenderQuadComponent::RenderQuadComponent(AObject* parent) : IComponent(parent){
	material = new LitMaterial();
}

RenderQuadComponent::~RenderQuadComponent() {
	delete this->material;
}

void RenderQuadComponent::LateUpdate() {
	Draw();
}

void RenderQuadComponent::Draw() const {
	if (!enableRender) return;

	glm::mat4 model = glm::mat4(1);
	model = glm::translate(model, this->parent->GetWorldPosition());
	model = glm::scale(model, this->parent->GetWorldScale());
	glm::quat rotation = parent->GetWorldRotation();
	glm::vec3 vectorRotation = glm::vec3(rotation.x, rotation.y, rotation.z);
	float angle = 2 * glm::acos(rotation.w);
	glm::rotate(model, angle, vectorRotation);

	Render::GetInstance().DrawQuad(model, material);
}
