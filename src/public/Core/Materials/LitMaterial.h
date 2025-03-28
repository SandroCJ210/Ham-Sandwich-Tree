#pragma once
#include <string>
#include <glm/glm.hpp>

#include "AMaterial.h"

class LitMaterial : public AMaterial {
private:
	unsigned int texture;
	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);

public:
	LitMaterial();
	~LitMaterial() override = default;

	void Use() override;

	LitMaterial* SetColor(float r, float g, float b, float a);
	LitMaterial* SetColor(glm::vec3 color);
	LitMaterial* SetTexture(const std::string &texturePath);

	[[nodiscard]] glm::vec3 GetColor() const { return this->color; };
};
