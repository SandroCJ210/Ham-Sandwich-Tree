#include <Core/Materials/LitMaterial.h>
#include <Core/Render/Render.h>
#include <Core/Render/Shader.h>

LitMaterial::LitMaterial() {
	texture = Render::GetInstance().GenerateTexture("Assets/Textures/Default.png");

	std::string vertexPath =	"Assets/Shaders/LitShader/Lit.vert";
	std::string fragmentPath =	"Assets/Shaders/LitShader/Lit.frag";
	this->shader = Render::GetInstance().CreateShader(vertexPath, fragmentPath);
}

void LitMaterial::Use() {
	this->shader->Use();
	this->shader->SetVector3("_color", this->color);
	this->shader->SetTexture(texture, 0);
}

LitMaterial* LitMaterial::SetColor(float r, float g, float b, float a) {
	this->color = glm::vec4(r, g, b, a);
	return this;
}

LitMaterial* LitMaterial::SetColor(const glm::vec3 color) {
	this->color = color;
	return this;
}

LitMaterial* LitMaterial::SetTexture(const std::string &texturePath) {
	this->texture = Render::GetInstance().GenerateTexture(texturePath);
	return this;
}
