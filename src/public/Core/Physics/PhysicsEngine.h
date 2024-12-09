#pragma once
#include <vector>

class RigidbodyComponent;
class ColliderComponent;
class AObject;

class PhysicsEngine {
private:
	std::vector<RigidbodyComponent*> rigidbodies;
	std::vector<ColliderComponent*> colliders;

public:
	PhysicsEngine();
	~PhysicsEngine();
	void Start(std::vector<AObject*> objects);
	void Update(float deltaTime);

	void AddRigidbody(RigidbodyComponent* rigidBody);
	void AddCollider(ColliderComponent* collider);

};