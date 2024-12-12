#pragma once
#include "Core/Materials/AMaterial.h"
#include "Math/Vector3.h"

class GizmosMaterial : public AMaterial {
public:

	Vector3 color = Vector3(1.0, 1.0, 1.0);

	GizmosMaterial();
	~GizmosMaterial();

	void SetColor(float r, float g, float b);
	void SetColor(Vector3 color);
	void SetColorUniform();
};