#pragma once
#include <vector>
#include <glm/glm.hpp>

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
		glm::vec2 position;
	};
	
private:
	static std::vector<RigidbodyComponent*> rigidbodies;
	static std::vector<ColliderComponent*> colliders;

public:
	//PhysicsEngine();
	//~PhysicsEngine();
	static void Start(std::vector<AObject*> objects);
	static void Update();

private:
	static void AddObjectRigidbodyAndCollider(AObject* object);
	static void AddRigidbody(RigidbodyComponent* rigidBody);
	static void AddCollider(ColliderComponent* collider);

	std::vector<ColliderComponent*> GetNearColliders(RigidbodyComponent* rigidbody);

public:
	void CalcMinAndMax(glm::vec2& min, glm::vec2& max, glm::vec2 center, glm::vec2 halfSize);
	
	bool PointIntersectsSquareCollider(glm::vec2 point, SquareColliderComponent* collider);
	bool SquareColliderIntesectsSquareCollider(
		SquareColliderComponent* collider1,
		SquareColliderComponent* collider2);

	glm::vec2 SquareColliderPenetration(
		SquareColliderComponent* collider1,
		SquareColliderComponent* collider2);

	Hit RaycastSquareCollider(
		glm::vec2 position,
		glm::vec2 direction,
		double distance,
		glm::vec2 colliderPosition,
		glm::vec2 colliderHalfSize);
};