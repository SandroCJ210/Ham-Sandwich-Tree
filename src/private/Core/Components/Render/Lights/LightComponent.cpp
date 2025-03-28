#include <Core/Window.h>
#include <Core/Components/Render/Lights/LightComponent.h>

LightComponent::LightComponent() {
	type = Point;

	range = 1.0f;
	color = glm::vec3(1.0f, 1.0f, 1.0f);
	intensity = 1.0f;
	//Window::GetInstance().GetActualScene()->lights.push_back(this);
}

void LightComponent::SetColor(glm::vec3 color) {
	this->color = color;
}
void LightComponent::SetIntensity(float intensity) {
	this->intensity = intensity;
}

void LightComponent::SetRange(float range) {
	this->range = range;
}



