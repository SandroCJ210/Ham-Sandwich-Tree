#include "Core/Materials/ColorMaterial.h"

#include <string>

#include "Core/Render/Shader.h"
#include "Core/Render/Render.h"

ColorMaterial::ColorMaterial() {
	std::string vertexPath =	"Assets/Shaders/ColorShader/ColorVert.glsl";
	std::string fragmentPath =	"Assets/Shaders/ColorShader/ColorFrag.glsl";
	this->shader = new Shader(vertexPath, fragmentPath);
}

ColorMaterial::~ColorMaterial() {
	delete this->shader;
}

void ColorMaterial::Use() {
	this->shader->Use();
	this->shader->SetVector3("_color", this->color);
}

void ColorMaterial::SetColor(float r, float g, float b) {
	this->color = glm::vec3(r, g, b);
}

void ColorMaterial::SetColor(glm::vec3 color) {
	this->color = color;
}

