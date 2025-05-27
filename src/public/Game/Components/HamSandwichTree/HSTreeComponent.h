#pragma once
#include <Core/Components/IComponent.h>
#include <vector>
#include <glm/glm.hpp>

class Point;
class HSTNode;

class HSTreeComponent : public IComponent {
private:

	bool is3D = false;
	int quantity = 100;
	float boundary = 10;

	std::vector<Point*> points;

	HSTNode* root = nullptr;

public:

	HSTreeComponent(bool is3D, int quatity, float boundary, AObject* parent);
	void Start() override;

private:
	void SpawnRandomPoints(int quantity, float boundary);
	void CreateTree();
	void CreateTreeAux(HSTNode* node);
	HSTNode* CreateNode(HSTNode* parent = nullptr);
	void SplitPoints(HSTNode* node);
	void CheckPoints();

};

class HSTNode {
public:
	HSTNode* root;
	float height = 0;
	
	std::vector<Point*> points;

	float medianProj;
	glm::vec3 direction;
	glm::vec3 medianPoint;

	HSTNode* parent;

	HSTNode* left;
	HSTNode* right;

};