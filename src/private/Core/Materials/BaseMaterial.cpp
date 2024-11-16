#include "Core/Materials/BaseMaterial.h"

#include "Core/Window.h"
#include "Core/Materials/Shader.h"

BaseMaterial::BaseMaterial() {
	std::string vertexPath = "Assets/Shaders/ColorRenderization/ColorRenderization.vert";
	std::string fragmentPath = "Assets/Shaders/ColorRenderization/ColorRenderization.frag";
	this->shader = new Shader(vertexPath, fragmentPath);
}

BaseMaterial::~BaseMaterial() {
	delete this->shader;
}

void BaseMaterial::SetColorUniform() {
	this->shader->SetVec3("_color", this->color);
}

void BaseMaterial::SetColor(Vector3 newColor) {
	this->color = newColor;
}


