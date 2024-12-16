#include "Core/Components/Render/RenderComponent.h"

#include "Core/Materials/BaseMaterial.h"
#include "Core/Render/Shader.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RenderComponent::RenderComponent(AObject* parent) : IComponent(parent){
	material = new BaseMaterial();
	
	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(material);
}

RenderComponent::~RenderComponent() {
	delete this->material;
}

void RenderComponent::LateUpdate() {
	Draw();
}

void RenderComponent::Draw() {
	if (!enableRender) return;

	Vector3 center = this->parent->GetGlobalPosition();
	Vector3 scale = this->parent->GetGlobalScale();

	material->shader->Use();

	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(material);
	baseMaterial->SetColorUniform();

	Render::GetInstance().DrawQuad(center, scale);
}
