#pragma once
#include "Core/Objects/AObject.h"

class RenderComponent;
class InputComponent;

class Player : public AObject {
public:
	Player(AObject* parent);
	~Player() override;

private:
	RenderComponent* renderComponent;
	InputComponent* inputComponent;

public:
	RenderComponent* GetRenderComponent() const { return renderComponent; };
	InputComponent* GetInputComponent() const { return inputComponent; };
};