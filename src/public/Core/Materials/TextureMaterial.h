#pragma once
#include <string>
#include <glm/glm.hpp>
#include "AMaterial.h"

class TextureMaterial : public AMaterial {
private:
	unsigned int texture;
	
public:
	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);
	
	TextureMaterial();
	~TextureMaterial();

	void Use() override;

	void SetColor(float r, float g, float b);
	void SetColor(glm::vec3 newColor);
	void SetTexture(std::string texturePath);
};
