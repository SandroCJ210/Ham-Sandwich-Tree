#include "Core/Materials/BaseMaterial.h"
#include "Core/Render/Render.h"
#include "Core/Render/Shader.h"

BaseMaterial::BaseMaterial() {
	std::string vertexPath =	"Assets/Shaders/BaseShader/BaseVert.glsl";
	std::string fragmentPath =	"Assets/Shaders/BaseShader/BaseFrag.glsl";
	this->shader = Render::GetInstance().CreateShader(vertexPath, fragmentPath);
}

BaseMaterial::~BaseMaterial() {
	delete this->shader;
}

void BaseMaterial::SetColor(glm::vec3 newColor) {
	this->color = newColor;
}

void BaseMaterial::SetColor(float r, float g, float b) {
	this->color = glm::vec3(r, g, b);
}

void BaseMaterial::SetTexture(std::string texturePath) {
	texture = Render::GetInstance().GenerateTexture(texturePath);
}
