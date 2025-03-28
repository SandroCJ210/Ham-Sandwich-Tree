#pragma once
#include <Core/Components/IComponent.h>
#include <glm/glm.hpp>


enum LightType {
	Point = 0,
};

class LightComponent : public IComponent {
private:

	LightType type;

	float range;
	glm::vec3 color;
	float intensity;

public:
	LightComponent();
	~LightComponent() override = default;
	void SetColor(glm::vec3 color);
	void SetIntensity(float intensity);
	void SetRange(float range);

	glm::vec3 GetColor() const { return this->color; }
	float GetIntensity() const { return this->intensity; }
};

