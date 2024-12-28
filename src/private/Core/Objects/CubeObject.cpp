#include "Core/Objects/CubeObject.h"

#include "Core/Components/Physics/3D/BoxColliderComponent.h"
#include "Core/Components/Render/RenderCubeComponent.h"

CubeObject::CubeObject(AObject* parent, std::string name) : AObject(parent, name){
	renderComponent = dynamic_cast<RenderCubeComponent*>(
		AddComponent(new RenderCubeComponent(this))
	);

	colliderComponent = dynamic_cast<BoxColliderComponent*>(
		AddComponent(new BoxColliderComponent(this))
	);
}
