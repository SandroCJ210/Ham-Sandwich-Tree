#include "Core/Components/Render/CameraComponent.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Core/Global.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"
#include "Util/Logger.h"

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
	
	//base rotation
	 // view = glm::rotate(view, glm::radians(180.0f), glm::vec3(0, 1, 0));
	
	glm::quat rotation = parent->GetWorldRotation();
	glm::vec3 vectorRotation = glm::vec3(rotation.x, rotation.y, rotation.z);
	float angle = 2 * glm::acos(rotation.w);
	// Logger::Log("Angle: " + std::to_string(angle));
	if (vectorRotation != glm::vec3(0))
		view = glm::rotate(view, angle, vectorRotation);
	
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