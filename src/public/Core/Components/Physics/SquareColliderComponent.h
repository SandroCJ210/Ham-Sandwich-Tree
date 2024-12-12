#pragma once
#include "ColliderComponent.h"
#include "Math/Vector2.h"

class SquareColliderComponent : public ColliderComponent{
public:
	Vector2 center;
	Vector2 halfSize;

private:
	Vector2 worldCenter;
	Vector2 worldHalfSize;

public:

	SquareColliderComponent(AObject* parent);
	SquareColliderComponent(AObject* parent, Vector2 center, Vector2 halfSize);
	~SquareColliderComponent() override;

	void Update(float deltatime) override;
	void LateUpdate() override;

	Vector2 GetMin();
	Vector2 GetMax();

};
