#include "Core/Components/Physics/RigidbodyComponent.h"
#include "Core/Components/Physics/ColliderComponent.h"
#include "Core/Objects/AObject.h"
#include "Core/Components/IComponent.h"

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

void RigidbodyComponent::PhysicsUpdate(float deltaTime) {
	parent->position += velocity * deltaTime;
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