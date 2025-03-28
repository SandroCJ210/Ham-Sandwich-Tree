#pragma once
#include <Core/Objects/EmptyObject.h>

class LightComponent;

class PointLight : public EmptyObject {
public:
	PointLight(AObject* parent, std::string name);
	~PointLight() override = default;

private:
	LightComponent* lightComponent;

public:
	LightComponent* GetLightComponent() const { return lightComponent; }
};
