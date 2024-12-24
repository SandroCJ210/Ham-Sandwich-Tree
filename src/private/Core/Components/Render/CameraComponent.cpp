#include "Core/Components/Render/CameraComponent.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Core/Global.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

CameraComponent::CameraComponent(AObject* parent) : IComponent(parent) {
}

CameraComponent::~CameraComponent() {}

void CameraComponent::Awake() {
	if (mainCamera) {
		Render::GetInstance().SetCurrentCamera(this);
	}
}

glm::mat4 CameraComponent::GetViewMatrix() {
	view = glm::mat4(1.0f);
	view = glm::translate(view, -1.0f * this->parent->GetWorldPosition());
	return view;
}

glm::mat4 CameraComponent::GetProjectionMatrix() {
	if (orthographic) {
		projection = glm::ortho(
			-1.0f * orthoSize * Global::SCREEN_FORMAT,	orthoSize * Global::SCREEN_FORMAT,	//x size
			-1.0f * orthoSize,							orthoSize,							//y size
			near,										far);								//z size
	}
	else {
		projection = glm::perspective(glm::radians(FOV), Global::SCREEN_FORMAT, near, far);
	}
	return projection;
}