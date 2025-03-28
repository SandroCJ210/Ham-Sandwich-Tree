#include <Core/Materials/ColorMaterial.h>
#include <Core/Render/Render.h>
#include <Core/Render/Shader.h>

ColorMaterial::ColorMaterial() {
	std::string vertexPath =	"Assets/Shaders/LitShader/Color.vert";
	std::string fragmentPath =	"Assets/Shaders/LitShader/Color.frag";
	this->shader = Render::GetInstance().CreateShader(vertexPath, fragmentPath);
}

void ColorMaterial::Use() {
	this->shader->Use();
	this->shader->SetVector3("_color", this->color);
}

ColorMaterial* ColorMaterial::SetColor(float r, float g, float b, float a) {
	this->color = glm::vec4(r, g, b, a);
	return this;
}

ColorMaterial* ColorMaterial::SetColor(const glm::vec3 color) {
	this->color = color;
	return this;
}
