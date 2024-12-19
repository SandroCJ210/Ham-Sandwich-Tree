#pragma once
#include <vector>
#include <glm/glm.hpp>

#include "Core/Components/IComponent.h"

class PhysicsEngine;
class ColliderComponent;

class RigidbodyComponent : public IComponent{
private:
	
	PhysicsEngine* physics;
	
	std::vector<ColliderComponent*> colliders;
	
public:
	glm::vec3 velocity;
	float mass = 1;
	//float drag;
	//float angularVelocity;
	//float angularDrag;
	//float torque;
	//float inertia;
	//float gravityScale;
	//bool isKinematic;

	RigidbodyComponent(AObject* parent);
	~RigidbodyComponent() override;

	void Awake() override;
	void End() override;

	void PhysicsUpdate(float fixedDeltaTime, std::vector<ColliderComponent*> nearColliders);

private:
	void DetectCollision(ColliderComponent* externalCollider, ColliderComponent* rbCollider, float fixedDeltaTime);	
	
public:
	void AddCollider(ColliderComponent* collider);
	void RemoveCollider(ColliderComponent* collider);
	void ClearColliders();
	std::vector<ColliderComponent*> GetColliders();
};
