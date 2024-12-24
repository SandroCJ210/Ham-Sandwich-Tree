#pragma once
#include "AObject.h"

class RenderCubeComponent;

class CubeObject : public AObject {
public:
	CubeObject(AObject* parent, std::string name);

private:
	RenderCubeComponent* renderComponent;
	// SquareColliderComponent* colliderComponent;

public:
	RenderCubeComponent* GetRenderComponent() const { return renderComponent; }
	// SquareColliderComponent* GetColliderComponent() const { return colliderComponent; }
	
};
