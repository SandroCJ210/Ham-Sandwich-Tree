#include <Core/Objects/3D/Cube.h>

#include <Core/Components/Physics/3D/BoxColliderComponent.h>
#include <Core/Components/Render/RenderCubeComponent.h>

Cube::Cube(AObject* parent, std::string name) : AObject(parent, name){
	renderComponent = dynamic_cast<RenderCubeComponent*>(
		AddComponent(new RenderCubeComponent(this))
	);

	colliderComponent = dynamic_cast<BoxColliderComponent*>(
		AddComponent(new BoxColliderComponent(this))
	);
}
