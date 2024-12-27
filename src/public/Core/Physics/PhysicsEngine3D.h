#pragma once
#include <vector>
#include <glm/glm.hpp>

class Rigidbody3DComponent;
class ACollider3DComponent;
class BoxColliderComponent;
class AObject;

class PhysicsEngine3D {
public:
	class Raycast3D {
	public:
		bool hit = false;
		float time;
		glm::vec3 position;
	};
	
private:
	static std::vector<Rigidbody3DComponent*> rigidbodies;
	static std::vector<ACollider3DComponent*> colliders;

public:
	static void Awake(std::vector<AObject*> objects);
	static void Update();

private:
	static void AddObjectRigidbodyAndCollider(AObject* object);
	static void AddRigidbody(Rigidbody3DComponent* rigidBody);
	static void AddCollider(ACollider3DComponent* collider);

	static std::vector<ACollider3DComponent*> GetNearColliders(Rigidbody3DComponent* rigidbody);

public:
	static void CalcMinAndMax(glm::vec3& min, glm::vec3& max, glm::vec3 center, glm::vec3 halfSize);

	static bool PointIntersectsBoxCollider(glm::vec3 point, BoxColliderComponent* collider);

	static bool BoxColliderIntesectsBoxCollider(
		BoxColliderComponent* collider1,
		BoxColliderComponent* collider2);

	static glm::vec3 BoxColliderPenetration(
		BoxColliderComponent* collider1,
		BoxColliderComponent* collider2);

	static Raycast3D RaycastBoxCollider(
		glm::vec3 position,
		glm::vec3 direction,
		double distance,
		glm::vec3 colliderPosition,
		glm::vec3 colliderHalfSize);
};