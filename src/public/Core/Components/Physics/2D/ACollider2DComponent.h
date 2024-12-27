#pragma once
#include "Core/Components/Physics/AColliderComponent.h"

class ACollider2DComponent : public AColliderComponent {
public:
	ACollider2DComponent(AObject* parent)
		: AColliderComponent(parent) {}
};
