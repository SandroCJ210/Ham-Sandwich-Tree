#pragma once
#include "AObject.h"

class RenderQuadComponent;
class SquareColliderComponent;

class SquareObject : public AObject {
public:
	SquareObject(AObject* parent, std::string name);

private:
	RenderQuadComponent* renderComponent;
	SquareColliderComponent* colliderComponent;

public:
	RenderQuadComponent* GetRenderComponent() const { return renderComponent; }
	SquareColliderComponent* GetColliderComponent() const { return colliderComponent; }
};
