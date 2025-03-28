#pragma once
#include <Core/Objects/AObject.h>

class BoxColliderComponent;
class RenderCubeComponent;

class Cube : public AObject {
public:
	Cube(AObject* parent, std::string name);

private:
	RenderCubeComponent* renderComponent;
	BoxColliderComponent* colliderComponent;

public:
	RenderCubeComponent* GetRenderComponent() const { return renderComponent; }
	BoxColliderComponent* GetBoxColliderComponent() const { return colliderComponent; }
};
