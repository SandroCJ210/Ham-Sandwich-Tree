#pragma once
#include <glm/glm.hpp>

#include "Core/Components/IComponent.h"

class CameraComponent : public IComponent{
private:
	glm::mat4 view;
	glm::mat4 projection;
	
public:
	bool mainCamera = false;
	bool orthographic = true;
	float orthoSize = 1.0f;
	
	float near = 0.1f;
	float far = 100.0f;

	float FOV = 45.0f;

	CameraComponent(AObject* parent);
	~CameraComponent();

	void Awake() override;

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	
};
