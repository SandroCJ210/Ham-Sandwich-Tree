#include "Core/Materials/BaseMaterial.h"

#include "Core/Window.h"
#include "Core/Materials/Shader.h"

BaseMaterial::BaseMaterial() {
	std::string vertexPath = Window::GetInstance().assetsFolder + "Shaders/ColorRenderization/ColorRenderization.vert";
	std::string fragmentPath = Window::GetInstance().assetsFolder + "Shaders/ColorRenderization/ColorRenderization.frag";
	this->shader = new Shader(vertexPath, fragmentPath);
}

BaseMaterial::~BaseMaterial() {
	delete this->shader;
}

bool BaseMaterial::SetColor(Vector3 newColor) {
	try {
		this->color = newColor;
		this->shader->SetVec3("color", newColor);
		return true;
	}
	catch (...) {
		return false;
	}
}


