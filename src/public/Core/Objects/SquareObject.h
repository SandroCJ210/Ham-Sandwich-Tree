#pragma once
#include "AObject.h"

class RenderComponent;

class SquareObject : public AObject {
public:
	SquareObject(AObject* parent);

private:
	RenderComponent* renderComponent;

public:
	RenderComponent* GetRenderComponent() const { return renderComponent; };
};
