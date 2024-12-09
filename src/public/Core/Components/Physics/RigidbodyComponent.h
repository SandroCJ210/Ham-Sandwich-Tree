#pragma once
#include "Core/Components/IComponent.h"
#include "Math/Vector2.h"
#include <vector>

class ColliderComponent;

class RigidbodyComponent : public IComponent {
private:
	std::vector<ColliderComponent*> colliders;

public:
	Vector2 velocity;
	float mass = 1;
	//float drag;
	//float angularVelocity;
	//float angularDrag;
	//float torque;
	//float inertia;
	//float gravityScale;
	//bool isKinematic;

	RigidbodyComponent(AObject* parent);
	~RigidbodyComponent();

	void Start() override;
	void End() override;

	void PhysicsUpdate(float deltaTime);

	void AddCollider(ColliderComponent* collider);
	void RemoveCollider(ColliderComponent* collider);
	void ClearColliders();
	std::vector<ColliderComponent*> GetColliders();
};