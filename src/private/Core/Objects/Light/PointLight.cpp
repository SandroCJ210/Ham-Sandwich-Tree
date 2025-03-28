#include <Core/Components/Render/Lights/LightComponent.h>
#include <Core/Objects/Light/PointLight.h>

PointLight::PointLight(AObject *parent, std::string name): EmptyObject(parent, name) {
	this->lightComponent = new LightComponent();
}
