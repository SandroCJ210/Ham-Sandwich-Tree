#include "Core/Objects/SquareObject.h"
#include "Core/Components/Render/RenderQuadComponent.h"
#include "Core/Components/Physics/2D/SquareColliderComponent.h"
#include "Core/Objects/AObject.h"

SquareObject::SquareObject(AObject* parent, std::string name) : AObject(parent, name){
	renderComponent = dynamic_cast<RenderQuadComponent*>(
		AddComponent(new RenderQuadComponent(this))
	);
	colliderComponent = dynamic_cast<SquareColliderComponent*>(
		AddComponent(new SquareColliderComponent(
			this,
			glm::vec2(0, 0),
			glm::vec2(0.5, 0.5)
			))
	);
}
