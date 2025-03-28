#pragma once
#include <glm/glm.hpp>

#include "AMaterial.h"

class ColorMaterial : public AMaterial{
private:
	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);

public:
	ColorMaterial();
	~ColorMaterial() override = default;

	void Use() override;

	ColorMaterial* SetColor(float r, float g, float b, float a);
	ColorMaterial* SetColor(glm::vec3 color);

	[[nodiscard]] glm::vec3 GetColor() const { return this->color; };

};
