#include <Game/Components/HamSandwichTree/HSTreeComponent.h>
#include <Game/Objects/HamSandwichTree/Point.h>
#include <algorithm>
#include <time.h>
#include <Util/Logger.h>

HSTreeComponent::HSTreeComponent(bool is3D, int quantity, float boundary, AObject* parent)
	: IComponent(parent) {

	this->is3D = is3D;
	this->quantity = quantity;
	this->boundary = boundary;

}

void HSTreeComponent::Start() {
	std::srand(time(NULL));
	SpawnRandomPoints(quantity, boundary);
	SplitPoints();
	CheckPoints();
}

void HSTreeComponent::SpawnRandomPoints(int quantity, float boundary) {

	for (int i = 0; i < quantity; i++) {
		float xPosition = -1*boundary + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2*boundary)));
		float yPosition = -1*boundary + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2*boundary)));
		float zPosition = 0;
		if(is3D)
			zPosition = -1*boundary + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2*boundary)));

		Point* point =  new Point("Point1", parent);
		point->position = glm::vec3(xPosition, yPosition, zPosition);

		points.push_back(point);
	}
}

void HSTreeComponent::SplitPoints() {
	float theta = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/glm::pi<float>()));
	float phi = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/glm::pi<float>()));
	
	if(is3D){
		direction = glm::vec3(
			glm::cos(theta) * glm::sin(phi),
			glm::sin(theta) * glm::sin(phi),
			glm::cos(phi)
		);

	}
	else{
		direction = glm::vec3(
			glm::cos(theta), 
			glm::sin(theta), 
			0);
	}

	std::vector<ProjectedPoint> projections;
	for (Point* p : points) {
		ProjectedPoint projPoint;

		projPoint.point = p->position;
		projPoint.projection = glm::dot(projPoint.point, direction);
		
		projections.push_back(projPoint);
	}

	std::sort(projections.begin(), projections.end());

	this->medianPoint = projections[(points.size()) / 2].point;
	this->medianProj = projections[(points.size()) / 2].projection;

	Point* line =  new Point("Line", parent);
	line->position = glm::vec3(medianPoint.x, medianPoint.y, 0);

	if(is3D){
		line->RotateEuler(glm::vec3(
			0,
			-1 * phi * 180 /glm::pi<float>(), 
			theta * 180 /glm::pi<float>()));
		line->scale = glm::vec3(0.05, boundary * 4, boundary * 4);
	}

	else {
		line->RotateEuler(glm::vec3(0, 0, (theta * 180 /glm::pi<float>()) - 90 ));
		line->scale = glm::vec3(boundary * 4, 0.05, 0.1);
	}
	line->SetColor(glm::vec3(0.0, 1.0, 0.0));	
}

void HSTreeComponent::CheckPoints() {
	int side1 = 0;
	int side2 = 0;
	for (Point* p : points) {
		ProjectedPoint projPoint;
		projPoint.point = p->position;
		float proj = glm::dot(projPoint.point, direction);
			
		if (proj < medianProj)
			side1++;
    	else
			side2++;
	}

	Logger::Log("Side 1: " + std::to_string(side1));
	Logger::Log("Side 2: " + std::to_string(side2));
}