#pragma once
#include <Core/Components/IComponent.h>
#include <vector>
#include <glm/glm.hpp>

class Point;

class HSTreeComponent : public IComponent {
private:

	bool is3D = false;
	int quantity = 100;
	float boundary = 10;

	float medianProj;
	glm::vec3 direction;
	glm::vec3 medianPoint;

	std::vector<Point*> points;

public:

	HSTreeComponent(bool is3D, int quatity, float boundary, AObject* parent);

	void Start() override;

	void SpawnRandomPoints(int quantity, float boundary);
	void SplitPoints();

	void CheckPoints();
};