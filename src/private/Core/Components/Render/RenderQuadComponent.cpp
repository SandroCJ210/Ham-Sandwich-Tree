#include "Core/Components/Render/RenderQuadComponent.h"

#include "Core/Materials/ColorMaterial.h"
#include "Core/Materials/TextureMaterial.h"
#include "Core/Render/Shader.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RenderQuadComponent::RenderQuadComponent(AObject* parent) : IComponent(parent){
	material = new ColorMaterial();
}

RenderQuadComponent::~RenderQuadComponent() {
	delete this->material;
}

void RenderQuadComponent::LateUpdate() {
	Draw();
}

void RenderQuadComponent::Draw() {
	if (!enableRender) return;

	glm::vec3 center = this->parent->GetWorldPosition();
	glm::vec3 scale = this->parent->GetWorldScale();

	ColorMaterial* _material = dynamic_cast<ColorMaterial*>(material);

	Render::GetInstance().DrawQuad(center, scale, material->shader, _material->color);
}
