#pragma once
#include "AObject.h"

class RenderComponent;
class SquareColliderComponent;

class SquareObject : public AObject {
public:
	SquareObject(AObject* parent, std::string name);

private:
	RenderComponent* renderComponent;
	SquareColliderComponent* colliderComponent;

public:
	RenderComponent* GetRenderComponent() const { return renderComponent; }
	SquareColliderComponent* GetColliderComponent() const { return colliderComponent; }
};
