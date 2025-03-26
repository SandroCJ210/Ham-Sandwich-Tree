#include "Core/Materials/TextureMaterial.h"
#include "Core/Render/Render.h"
#include "Core/Render/Shader.h"

TextureMaterial::TextureMaterial() {
	std::string vertexPath =	"Assets/Shaders/TextureShader/TextureVert.glsl";
	std::string fragmentPath =	"Assets/Shaders/TextureShader/TextureFrag.glsl";
	this->shader = Render::GetInstance().CreateShader(vertexPath, fragmentPath);
}

TextureMaterial::~TextureMaterial() {
	delete this->shader;
}

void TextureMaterial::Use() {
	this->shader->Use();
	this->shader->SetVector3("_color", this->color);
	this->shader->SetTexture(texture, 0);
	
}

void TextureMaterial::SetColor(float r, float g, float b) {
	this->color = glm::vec3(r, g, b);
}

void TextureMaterial::SetColor(glm::vec3 newColor) {
	this->color = newColor;
}

void TextureMaterial::SetTexture(std::string texturePath) {
	texture = Render::GetInstance().GenerateTexture(texturePath);
}
