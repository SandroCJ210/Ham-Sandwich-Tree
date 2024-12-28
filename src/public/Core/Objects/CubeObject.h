#pragma once
#include "AObject.h"

class BoxColliderComponent;
class RenderCubeComponent;

class CubeObject : public AObject {
public:
	CubeObject(AObject* parent, std::string name);

private:
	RenderCubeComponent* renderComponent;
	BoxColliderComponent* colliderComponent;

public:
	RenderCubeComponent* GetRenderComponent() const { return renderComponent; }
	BoxColliderComponent* GetBoxColliderComponent() const { return colliderComponent; }
};
