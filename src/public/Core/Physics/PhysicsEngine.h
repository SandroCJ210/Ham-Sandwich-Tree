#pragma once
#include <vector>

#include "Math/Vector2.h"

class RigidbodyComponent;
class ColliderComponent;
class SquareColliderComponent;
class AObject;

class PhysicsEngine {
public:
	class Hit {
	public:
		bool hit = false;
		float time;
		Vector2 position;
	};
	
private:
	std::vector<RigidbodyComponent*> rigidbodies;
	std::vector<ColliderComponent*> colliders;

public:
	PhysicsEngine();
	~PhysicsEngine();
	void Start(std::vector<AObject*> objects);
	void Update();

private:
	void AddObjectRigidbodyAndCollider(AObject* object);
	void AddRigidbody(RigidbodyComponent* rigidBody);
	void AddCollider(ColliderComponent* collider);

	std::vector<ColliderComponent*> GetNearColliders(RigidbodyComponent* rigidbody);

public:
	void CalcMinAndMax(Vector2& min, Vector2& max, Vector2 center, Vector2 halfSize);
	
	bool PointIntersectsSquareCollider(Vector2 point, SquareColliderComponent* collider);
	bool SquareColliderIntesectsSquareCollider(
		SquareColliderComponent* collider1,
		SquareColliderComponent* collider2);

	Vector2 SquareColliderPenetration(
		SquareColliderComponent* collider1,
		SquareColliderComponent* collider2);

	Hit RaycastSquareCollider(
		Vector2 position,
		Vector2 direction,
		double distance,
		Vector2 colliderPosition,
		Vector2 colliderHalfSize);
};