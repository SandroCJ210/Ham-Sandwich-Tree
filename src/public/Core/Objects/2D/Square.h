#pragma once
#include <Core/Objects/EmptyObject.h>

class RenderQuadComponent;
class SquareColliderComponent;

class Square : public EmptyObject {
public:
	Square(AObject* parent, std::string name, ASceneController* targetScene);

private:
	RenderQuadComponent* renderComponent;
	SquareColliderComponent* colliderComponent;

public:
	[[nodiscard]] RenderQuadComponent* GetRenderComponent() const { return renderComponent; }
	[[nodiscard]] SquareColliderComponent* GetColliderComponent() const { return colliderComponent; }
};
