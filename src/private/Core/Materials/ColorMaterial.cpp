#include <Core/Materials/ColorMaterial.h>
#include <Core/Render/Render.h>
#include <Core/Render/Shader.h>

ColorMaterial::ColorMaterial() {
	std::string vertexPath =	"Assets/Shaders/ColorShader/Color.vert";
	std::string fragmentPath =	"Assets/Shaders/ColorShader/Color.frag";
	this->shader = new Shader(vertexPath, fragmentPath);
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
