#include "Core/Materials/GizmosMaterial.h"
#include "Core/Render/Shader.h"
#include <string>

#include "Core/Render/Render.h"

GizmosMaterial::GizmosMaterial() {
	std::string vertexPath = "Assets/Shaders/ColorRenderization/ColorRenderization.vert";
	std::string fragmentPath = "Assets/Shaders/ColorRenderization/ColorRenderization.frag";
	this->shader = new Shader(vertexPath, fragmentPath);
}

GizmosMaterial::~GizmosMaterial() {
	delete this->shader;
}

void GizmosMaterial::SetColor(float r, float g, float b) {
	this->color = Vector3(r, g, b);
}

void GizmosMaterial::SetColor(Vector3 color) {
	this->color = color;
}

void GizmosMaterial::SetColorUniform() {
	this->shader->Use();
	this->shader->SetVector3("_color", this->color);
}

