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
	//GenBuffers();
}

RenderComponent::~RenderComponent() {
	delete this->material;
}

void RenderComponent::LateUpdate() {
	CalcVertex();
	UpdateBuffers();
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

void RenderComponent::GenBuffers() {
	

	//glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	//UpdateBuffers();

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	/*glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);*/
}

void RenderComponent::UpdateBuffers() {
	//CalcVertex();
	//
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
}

void RenderComponent::Draw() {
	material->shader->Use();

	BaseMaterial* baseMaterial = dynamic_cast<BaseMaterial*>(material);
	baseMaterial->SetColor(Vector3(1.0, 1.0, 1.0));
	baseMaterial->SetColorUniform();

	Render::GetInstance().DrawQuad(vertices, sizeof(vertices), indices, sizeof(indices));
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RenderComponent::SetScale(Vector3 scale) {
	this->scale = scale;
}
