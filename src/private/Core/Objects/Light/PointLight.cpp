#include <Core/Components/Render/Lights/LightComponent.h>
#include <Core/Objects/Light/PointLight.h>

PointLight::PointLight(const std::string &_name, AObject* _parent, ASceneController* _scene)
	: AObject(_name, _parent, _scene) {
	this->lightComponent = new LightComponent();
}
