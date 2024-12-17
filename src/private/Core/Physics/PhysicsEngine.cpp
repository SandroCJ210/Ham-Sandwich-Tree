#include "Core/Physics/PhysicsEngine.h"

#include <iostream>

#include "Core/Global.h"
#include "Core/Components/Physics/RigidbodyComponent.h"
#include "Core/Components/Physics/ColliderComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Math/Vector2.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Color.h"
#include "Core/Render/Render.h"
#include "Util/Logger.h"

PhysicsEngine::PhysicsEngine() {
	rigidbodies = std::vector<RigidbodyComponent*>();
	colliders = std::vector<ColliderComponent*>();
}

PhysicsEngine::~PhysicsEngine() {
}

void PhysicsEngine::Start(std::vector<AObject*> objects) {
	for (AObject* object : objects) {
		AddObjectRigidbodyAndCollider(object);
	}
}

void PhysicsEngine::Update() {
	for (int i = 0; i < rigidbodies.size(); i++) {
		std::vector<ColliderComponent*> nearColliders = GetNearColliders(rigidbodies[i]);
		rigidbodies[i]->PhysicsUpdate(Global::FIXED_DELTA_TIME, nearColliders);
	}
}

void PhysicsEngine::AddObjectRigidbodyAndCollider(AObject* object) {
	for (IComponent* component : object->components) {

		RigidbodyComponent* rigidbody = dynamic_cast<RigidbodyComponent*>(component);
		if (rigidbody != nullptr) {
			AddRigidbody(rigidbody);
			continue;
		}

		ColliderComponent* collider = dynamic_cast<ColliderComponent*>(component);
		if (collider != nullptr) {
			AddCollider(collider);
			continue;
		}
	}

	for (AObject* child : object->children) {
		AddObjectRigidbodyAndCollider(child);
	}
}

void PhysicsEngine::AddRigidbody(RigidbodyComponent* rigidbody) {
	rigidbodies.push_back(rigidbody);
}

void PhysicsEngine::AddCollider(ColliderComponent* collider) {
	colliders.push_back(collider);
}

std::vector<ColliderComponent*> PhysicsEngine::GetNearColliders(RigidbodyComponent* rigidbody) {
	std::vector<ColliderComponent*> nearColliders = std::vector<ColliderComponent*>();

	Vector3 maxDistance = rigidbody->velocity != Vector3(0) ?
		rigidbody->velocity : rigidbody->parent->GetGlobalScale();
	
	for (ColliderComponent* collider : colliders) {
		if (rigidbody->parent == collider->parent) continue;

		Vector3 distance = rigidbody->parent->GetGlobalPosition() - collider->parent->GetGlobalPosition();
		
		if (distance.SquaredMagnitude() <= maxDistance.SquaredMagnitude()) {
			nearColliders.push_back(collider);
		}
	}

	return nearColliders;
}

void PhysicsEngine::CalcMinAndMax(Vector2& min, Vector2& max, Vector2 center, Vector2 halfSize) {
	min = center - halfSize;
	max = center + halfSize;
}

bool PhysicsEngine::PointIntersectsSquareCollider(Vector2 point, SquareColliderComponent* collider) {
	Vector2 min, max;
	CalcMinAndMax(min, max, collider->GetWorldCenter(), collider->GetWorldHalfSize());

	return (
		point.x >= min.x &&
		point.x <= max.x &&
		point.y >= min.y &&
		point.y <= max.y
	);
}

bool PhysicsEngine::SquareColliderIntesectsSquareCollider(
	SquareColliderComponent* collider1,
	SquareColliderComponent* collider2
) {
	Vector2 resultPosition = collider1->GetWorldCenter() - collider2->GetWorldCenter();
	Vector2 resultHalfSize = collider1->GetWorldHalfSize() + collider2->GetWorldHalfSize();

	Vector2 min, max;
	CalcMinAndMax(min, max, resultPosition, resultHalfSize);

	return (
		min.x <= 0 &&
		max.x >= 0 &&
		min.y <= 0 &&
		max.y >= 0
	);
}

Vector2 PhysicsEngine::SquareColliderPenetration(
	SquareColliderComponent* collider1,
	SquareColliderComponent* collider2
) {
	Vector2 resultPosition = collider1->GetWorldCenter() - collider2->GetWorldCenter();
	Vector2 resultHalfSize = collider1->GetWorldHalfSize() + collider2->GetWorldHalfSize();

	Vector2 min, max;
	CalcMinAndMax(min, max, resultPosition, resultHalfSize);

	Vector2 penetration = Vector2(min.x, 0);
	
	float minDistance = std::abs(min.x);

	if (std::abs(max.x) < minDistance) {
		minDistance = std::abs(max.x);
		penetration.x = max.x;
	}

	if (std::abs(min.y) < minDistance) {
		minDistance = std::abs(min.y);
		penetration.x = 0;
		penetration.y = min.y;
	}
	
	if (std::abs(max.y) < minDistance) {
		penetration.x = 0;
		penetration.y = max.y;
	}
	
	return penetration;
}

PhysicsEngine::Hit PhysicsEngine::RaycastSquareCollider(
	Vector2 position,
	Vector2 direction,
	double distance,
	Vector2 colliderPosition,
	Vector2 colliderHalfSize) {
	
	Hit hit;
	
	if (std::abs(direction.SquaredMagnitude()-1) > 1e-10) {
		direction = direction.Normalize();
	}
	
	Vector2 magnitude = direction * distance;
	
	Vector2 min, max;
	CalcMinAndMax(min, max, colliderPosition, colliderHalfSize);

	float lastEntry = -INFINITY;
	float firstExit = INFINITY;
	
	for (int i = 0; i < 2; i++) {
		if (std::abs(magnitude[i]) != 0) {
			float t1 = (min[i] - position[i]) / magnitude[i];
			float t2 = (max[i] - position[i]) / magnitude[i];

			lastEntry = std::max(lastEntry, std::min(t1, t2));
			firstExit = std::min(firstExit, std::max(t1, t2));
		}
		else if (position[i] <= min[i] || position[i] >= max[i]) {
			return hit;
		}
	}

	if (firstExit > lastEntry && firstExit > 0 && lastEntry < 1) {
		lastEntry = std::max(lastEntry, 0.0f);
		hit.hit = true;
		hit.time = lastEntry;
		hit.position = position + magnitude * lastEntry;
	}

	return hit;
}


