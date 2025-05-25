#include "Game/Objects/HamSandwichTree/Point.h"

Point::Point(const std::string& _name, AObject* _parent, ASceneController* _scene)
	: AObject(_name, _parent, _scene) {

	renderComponent = dynamic_cast<RenderCubeComponent*>(
		AddComponent(new RenderCubeComponent(this)));
}

