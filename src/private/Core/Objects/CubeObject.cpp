#include "Core/Objects/CubeObject.h"

#include "Core/Components/Render/RenderCubeComponent.h"

CubeObject::CubeObject(AObject* parent, std::string name) : AObject(parent, name){
	renderComponent = dynamic_cast<RenderCubeComponent*>(
		AddComponent(new RenderCubeComponent(this))
	);
}
