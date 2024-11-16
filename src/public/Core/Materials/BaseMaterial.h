#pragma once
#include "AMaterial.h"
#include "Math/Vector3.h"

class BaseMaterial : public AMaterial {
public:

	Vector3 color = Vector3(1.0, 1.0, 1.0);
	
	BaseMaterial();
	~BaseMaterial();

	void SetColorUniform();
	void SetColor(Vector3 newColor);
};
