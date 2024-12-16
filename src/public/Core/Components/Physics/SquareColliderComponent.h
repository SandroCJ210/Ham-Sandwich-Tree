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

	void FixedUpdate() override;
	void Update(double deltatime) override;
	void LateUpdate() override;

	Vector2 GetWorldCenter() const { return worldCenter; }
	Vector2 GetWorldHalfSize() const { return worldHalfSize; }
};
