#pragma once
#include <vector>
#include <glm/glm.hpp>

class SquareColliderComponent;
class AObject;
class ACollider2DComponent;
class Rigidbody2DComponent;

class PhysicsEngine2D {
public:
	class Raycast2D {
	public:
		bool hit = false;
		float time;
		glm::vec2 position;
	};
private:
	static std::vector<Rigidbody2DComponent*> rigidbodies;
	static std::vector<ACollider2DComponent*> colliders;

public:
	static void Awake(std::vector<AObject*> objects);
	static void Update();

private:
	static void AddObjectRigidbodyAndCollider(AObject* object);
	static void AddRigidbody(Rigidbody2DComponent* rigidBody);
	static void AddCollider(ACollider2DComponent* collider);

	static std::vector<ACollider2DComponent*> GetNearColliders(Rigidbody2DComponent* rigidbody);
	
public:
	static void CalcMinAndMax(glm::vec2& min, glm::vec2& max, glm::vec2 center, glm::vec2 halfSize);
	
	static bool PointIntersectsSquareCollider(glm::vec2 point, SquareColliderComponent* collider);

	static bool SquareColliderIntesectsSquareCollider(
		SquareColliderComponent* collider1,
		SquareColliderComponent* collider2);

	static glm::vec2 SquareColliderPenetration(
		SquareColliderComponent* collider1,
		SquareColliderComponent* collider2);

	static Raycast2D RaycastSquareCollider(
		glm::vec2 position,
		glm::vec2 direction,
		double distance,
		glm::vec2 colliderPosition,
		glm::vec2 colliderHalfSize);
};
