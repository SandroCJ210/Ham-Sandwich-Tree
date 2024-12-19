#pragma once
#include <glm/glm.hpp>

#include "Core/Materials/AMaterial.h"

class GizmosMaterial : public AMaterial {
public:

	glm::vec3 color = glm::vec3(1.0, 1.0, 1.0);

	GizmosMaterial();
	~GizmosMaterial();

	void SetColor(float r, float g, float b);
	void SetColor(glm::vec3 color);
	void SetColorUniform();
};