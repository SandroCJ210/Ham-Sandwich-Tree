#include "Core/Components/Physics/RigidbodyComponent.h"

#include <vector>
#include "Core/Window.h"
#include "Core/Components/Physics/ColliderComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RigidbodyComponent::RigidbodyComponent(AObject* parent) : IComponent(parent) {
	velocity = glm::vec3(0.0f);
	physics = nullptr;
}

RigidbodyComponent::~RigidbodyComponent() {
}

void RigidbodyComponent::Awake() {
	physics = Window::GetInstance().GetActualScene()->GetPhysicsEngine();
	for (IComponent* component : parent->components) {
		ColliderComponent* collider = dynamic_cast<ColliderComponent*>(component);
		if (collider != nullptr) {
			AddCollider(collider);
		}
	}
}

void RigidbodyComponent::End() {
	colliders.clear();
}

void RigidbodyComponent::PhysicsUpdate(float fixedDeltaTime, std::vector<ColliderComponent*> nearColliders) {
	
	for (ColliderComponent* externalCollider : nearColliders) {
		for (ColliderComponent* rbCollider: colliders) {
			DetectCollision(externalCollider, rbCollider, fixedDeltaTime);
		}
	}
	
	if (velocity != glm::vec3(0))
		parent->SetGlobalPosition(parent->GetGlobalPosition() + velocity * fixedDeltaTime);
}

void RigidbodyComponent::DetectCollision(
	ColliderComponent* externalCollider,
	ColliderComponent* rbCollider, 
	float fixedDeltaTime) {
	
	if (externalCollider->isTrigger || rbCollider->isTrigger) return;

	SquareColliderComponent* externalSquareCollider = dynamic_cast<SquareColliderComponent*>(externalCollider);
	SquareColliderComponent* rbSquareCollider = dynamic_cast<SquareColliderComponent*>(rbCollider);

	if (externalSquareCollider == nullptr || rbSquareCollider == nullptr) return;

	//simulated collider for the collision detection
	glm::vec2 sumCenter = externalSquareCollider->GetWorldCenter();
	glm::vec2 sumHalfSize = (
		externalSquareCollider->GetWorldHalfSize() +
		rbSquareCollider->GetWorldHalfSize()
		);
	
	if (velocity.x != 0) {
		PhysicsEngine::Hit hit = physics->RaycastSquareCollider(
			rbSquareCollider->GetWorldCenter(),
			velocity.x > 0 ? glm::vec2(1, 0) : glm::vec2(-1, 0),
			glm::length(velocity) * fixedDeltaTime,
			sumCenter,
			sumHalfSize
		);
		
		if (hit.hit) {
			parent->SetGlobalPosition(glm::vec3(hit.position, 0));
			velocity.x = 0;
		}
	}

	if (velocity.y != 0) {
		PhysicsEngine::Hit hit = physics->RaycastSquareCollider(
			rbSquareCollider->GetWorldCenter(),
			velocity.y > 0 ? glm::vec2(0, 1) : glm::vec2(0, -1),
			glm::length(velocity) * fixedDeltaTime,
			sumCenter,
			sumHalfSize
		);
		
		if (hit.hit) {
			parent->SetGlobalPosition(glm::vec3(hit.position, 0));
			velocity.y = 0;
		}
	}
	
	if (velocity == glm::vec3(0)) {
		if (physics->SquareColliderIntesectsSquareCollider(externalSquareCollider, rbSquareCollider)) {
			
			glm::vec2 penetration = physics->SquareColliderPenetration(externalSquareCollider, rbSquareCollider);
			
			parent->SetGlobalPosition(parent->GetGlobalPosition() + glm::vec3(penetration, 0) * 1.01f);
		}
	}
}


void RigidbodyComponent::AddCollider(ColliderComponent* collider) {
	colliders.push_back(collider);
}

void RigidbodyComponent::RemoveCollider(ColliderComponent* collider) {
	for (int i = 0; i < colliders.size(); i++) {
		if (colliders[i] == collider) {
			colliders.erase(colliders.begin() + i);
			break;
		}
	}
}

void RigidbodyComponent::ClearColliders() {
	colliders.clear();
}

std::vector<ColliderComponent*> RigidbodyComponent::GetColliders() {
	return colliders;
}