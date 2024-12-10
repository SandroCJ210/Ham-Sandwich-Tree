#include "Core/Components/RenderComponent.h"

#include <glad/glad.h>

#include "Core/Materials/BaseMaterial.h"
#include "Core/Materials/AMaterial.h"
#include "Core/Materials/Shader.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"
#include <Core/Window.h>

RenderComponent::RenderComponent(AObject* parent) : IComponent(parent){
	material = new BaseMaterial();
	
	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(material);
	
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 3;
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;

	CalcVertex();
}

RenderComponent::~RenderComponent() {
	delete this->material;
}

void RenderComponent::LateUpdate() {
	CalcVertex();
	Draw();
}


void RenderComponent::CalcVertex() {
	Vector3 center = this->parent->position;
	float screenFormat = (float)Window::GetInstance().WIDTH / (float)Window::GetInstance().HEIGHT;
	
	float scaledWidth = (width / screenFormat) * scale.x;
	float scaledHeight = height * scale.y;

	//bottom left
	vertices[0] = center.x - scaledWidth / 2;
	vertices[1] = center.y - scaledHeight / 2;
	vertices[2] = 0;

	//bottom right
	vertices[3] = center.x + scaledWidth / 2;
	vertices[4] = center.y - scaledHeight / 2;
	vertices[5] = 0;

	//top right
	vertices[6] = center.x + scaledWidth / 2;
	vertices[7] = center.y + scaledHeight / 2;
	vertices[8] = 0;

	//top left
	vertices[9] = center.x - scaledWidth / 2;
	vertices[10] = center.y + scaledHeight / 2;
	vertices[11] = 0;
}

void RenderComponent::Draw() {
	material->shader->Use();

	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(material);
	baseMaterial->SetColorUniform();

	Render::GetInstance().DrawQuad(vertices);
}

void RenderComponent::SetScale(Vector3 scale) {
	this->scale = scale;
}
