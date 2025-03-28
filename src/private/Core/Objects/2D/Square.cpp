#include <Core/Objects/2D/Square.h>
#include <Core/Components/Render/RenderQuadComponent.h>
#include <Core/Components/Physics/2D/SquareColliderComponent.h>

Square::Square(const std::string &_name, AObject* _parent, ASceneController* _scene)
	: AObject(_name, _parent, _scene){
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
