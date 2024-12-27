#pragma once
#include <glm/glm.hpp>

#include "ACollider3DComponent.h"

class BoxColliderComponent : public ACollider3DComponent {
public:
	glm::vec3 center;
	glm::vec3 halfSize;

private:
	glm::vec3 worldCenter;
	glm::vec3 worldHalfSize;

public:
	BoxColliderComponent(AObject* parent);
	BoxColliderComponent(AObject* parent, glm::vec3 center, glm::vec3 halfSize);
	~BoxColliderComponent() override;

	void FixedUpdate() override;
	void LateUpdate() override;

	glm::vec3 GetWorldCenter() const { return worldCenter; }
	glm::vec3 GetWorldHalfSize() const { return worldHalfSize; }
};
