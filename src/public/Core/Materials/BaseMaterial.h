#pragma once
#include "AMaterial.h"
#include "Math/Vector3.h"

class BaseMaterial : public AMaterial {
public:
	Vector3 color;
	
	BaseMaterial();
	~BaseMaterial();

	bool SetColor(Vector3 newColor);
};
