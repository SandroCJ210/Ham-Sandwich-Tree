#pragma once
#include <vector>
#include <glm/glm.hpp>

#include "Core/Components/IComponent.h"

class PhysicsEngine3D;
class ACollider3DComponent;

class Rigidbody3DComponent : public IComponent{
private:
	std::vector<ACollider3DComponent*> colliders;
	
public:
	glm::vec3 velocity;
	float mass = 1;

	Rigidbody3DComponent(AObject* parent);
	~Rigidbody3DComponent() override;

	void Awake() override;
	void End() override;

	void PhysicsUpdate(
		std::vector<ACollider3DComponent*> nearColliders,
		float fixedDeltaTime);

private:
	void DetectCollision(
		ACollider3DComponent* externalCollider,
		ACollider3DComponent* rbCollider,
		float fixedDeltaTime);	
	
public:
	void AddCollider(ACollider3DComponent* collider);
	void RemoveCollider(ACollider3DComponent* collider);
	void ClearColliders();
	std::vector<ACollider3DComponent*> GetColliders();
};
