#include "Game/Objects/HamSandwichTree/Point.h"
#include <Core/Materials/LitMaterial.h>

Point::Point(
	const std::string& _name, 
	AObject* _parent, 
	ASceneController* _scene)
	: AObject(_name, _parent, _scene) {

	scale = glm::vec3(0.3f);
	renderComponent = dynamic_cast<RenderCubeComponent*>(
		AddComponent(new RenderCubeComponent(this)));
}

void Point::SetColor(glm::vec3 color) {
	LitMaterial* material = dynamic_cast<LitMaterial*>(
		renderComponent->material
	);

	material->SetColor(color);
}

