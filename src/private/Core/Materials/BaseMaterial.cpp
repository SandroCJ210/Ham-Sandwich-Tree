#include "Core/Materials/BaseMaterial.h"
#include "Core/Window.h"
#include "Core/Render/Render.h"
#include "Core/Render/Shader.h"

BaseMaterial::BaseMaterial() {
	std::string vertexPath = "Assets/Shaders/ColorRenderization/ColorRenderization.vert";
	std::string fragmentPath = "Assets/Shaders/ColorRenderization/ColorRenderization.frag";
	this->shader = Render::GetInstance().CreateShader(vertexPath, fragmentPath);
}

BaseMaterial::~BaseMaterial() {
	delete this->shader;
}

void BaseMaterial::SetColor(Vector3 newColor) {
	this->color = newColor;
}

void BaseMaterial::SetColor(float r, float g, float b) {
	this->color = Vector3(r, g, b);
}

void BaseMaterial::SetColorUniform() {
	this->shader->SetVector3("_color", this->color);
}


