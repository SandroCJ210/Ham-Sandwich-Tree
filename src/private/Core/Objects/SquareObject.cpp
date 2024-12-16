#include "Core/Objects/SquareObject.h"
#include "Core/Components/Render/RenderComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Core/Objects/AObject.h"

SquareObject::SquareObject(AObject* parent, std::string name) : AObject(parent, name){
	renderComponent = dynamic_cast<RenderComponent*>(
		AddComponent(new RenderComponent(this))
	);
	colliderComponent = dynamic_cast<SquareColliderComponent*>(
		AddComponent(new SquareColliderComponent(
			this,
			Vector2(0, 0),
			Vector2(0.5, 0.5)
			))
	);
}
