#include "Core/Objects/Player.h"
#include "Core/Components/RenderComponent.h"
#include "Core/Components/InputComponent.h"


Player::Player(AObject* parent) : AObject(parent) {
	renderComponent = dynamic_cast<RenderComponent*>(AddComponent(new RenderComponent(this)));
	inputComponent = dynamic_cast<InputComponent*>(AddComponent(new InputComponent(this)));
}

Player::~Player() {
	delete renderComponent;
	delete inputComponent;
}