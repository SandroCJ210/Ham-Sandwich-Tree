#pragma once
#include "AObject.h"

class RenderComponent;

class SquareObject : public AObject {
public:
	SquareObject(AObject* parent, std::string name);

private:
	RenderComponent* renderComponent;

public:
	RenderComponent* GetRenderComponent() const { return renderComponent; };
};
