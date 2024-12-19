#pragma once
#include <glm/glm.hpp>
#include "AMaterial.h"

class BaseMaterial : public AMaterial {
public:

	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);
	
	BaseMaterial();
	~BaseMaterial();

	void SetColor(float r, float g, float b);
	void SetColor(glm::vec3 newColor);
	void SetColorUniform();
};
