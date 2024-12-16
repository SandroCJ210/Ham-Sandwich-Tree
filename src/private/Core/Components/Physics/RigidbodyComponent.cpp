#include "Core/Components/Physics/RigidbodyComponent.h"

#include <iostream>

#include "Core/Window.h"
#include "Core/Components/Physics/ColliderComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Core/Objects/AObject.h"
#include "Core/Render/Render.h"

RigidbodyComponent::RigidbodyComponent(AObject* parent) : IComponent(parent) {
	velocity = Vector2(0, 0);
}

RigidbodyComponent::~RigidbodyComponent() {
}

void RigidbodyComponent::Start() {
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
	PhysicsEngine* physics = Window::GetInstance().GetActualScene()->GetPhysicsEngine();
	
	for (ColliderComponent* externalCollider : nearColliders) {
		for (ColliderComponent* rbCollider: colliders) {

			if (externalCollider->isTrigger || rbCollider->isTrigger) continue;

			SquareColliderComponent* externalSquareCollider = dynamic_cast<SquareColliderComponent*>(externalCollider);
			SquareColliderComponent* rbSquareCollider = dynamic_cast<SquareColliderComponent*>(rbCollider);

			if (externalSquareCollider == nullptr || rbSquareCollider == nullptr) continue;

			//simulated collider for the collision detection
			Vector2 sumCenter = externalSquareCollider->GetWorldCenter();
			Vector2 sumHalfSize = (
				externalSquareCollider->GetWorldHalfSize() +
				rbSquareCollider->GetWorldHalfSize()
				);
			
			if (velocity != Vector2::zero) {
				//Vector2 magnitude = (normalizedVelocity * fixedDeltaTime);
				
				PhysicsEngine::Hit hit = physics->RaycastSquareCollider(
					rbSquareCollider->GetWorldCenter(),
					velocity.Normalize(),
					velocity.Magnitude() * fixedDeltaTime,
					sumCenter,
					sumHalfSize
				);
				
				if (hit.hit) {
					parent->SetGlobalPosition(hit.position);
					velocity = Vector2::zero;
				}
			}
			
			if (velocity == Vector2::zero) {
				if (physics->SquareColliderIntesectsSquareCollider(externalSquareCollider, rbSquareCollider)) {
					Vector2 penetration = physics->SquareColliderPenetration(externalSquareCollider, rbSquareCollider);
					parent->SetGlobalPosition(parent->GetGlobalPosition() + penetration * 1.01f);
					
					velocity = Vector2::zero;
				}
			}
		}
	}
	
	if (velocity != Vector3::zero)
		parent->SetGlobalPosition(parent->GetGlobalPosition() + velocity * fixedDeltaTime);
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