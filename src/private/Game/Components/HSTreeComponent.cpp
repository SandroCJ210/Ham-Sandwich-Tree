#include <Game/Components/HSTreeComponent.h>
#include <Game/Objects/Point.h>
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
	//Aparición de puntos aleatorios
	SpawnRandomPoints(quantity, boundary);
	CreateTree();
}

void HSTreeComponent::CreateTree() {
	root = CreateNode();
	root->points = this->points;
	CreateTreeAux(root);
}

void HSTreeComponent::CreateTreeAux(HSTNode* node) {
	// si el nodo tiene menos de 5 puntos (valor arbitrário, puede ser cualquier k)
	if(node->points.size() < 5)
		return;
	// parte los nodos en 2 grupos y crea los nodos hijos
	SplitPoints(node);
	//repite el mismo codigo para cada hijo
	CreateTreeAux(node->left);
	CreateTreeAux(node->right);
}

HSTNode* HSTreeComponent::CreateNode(HSTNode* parent) {
	HSTNode* newNode = new HSTNode();
	newNode->root = this->root;
	newNode->parent = parent;
	if(parent != nullptr)
		newNode->height = parent->height + 1;
	return newNode;
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

void HSTreeComponent::SplitPoints(HSTNode* node) {
	//angulos aleatorios para el hiperplano
	float theta = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/glm::pi<float>()));
	float phi = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/glm::pi<float>()));
	
	//variables de apoyo
	float medianProj;
	glm::vec3 direction;
	glm::vec3 medianPoint;

	node->left = CreateNode(node);
	node->right = CreateNode(node);

	//definicion del vector
	if(is3D) {
		direction = glm::vec3(
			glm::cos(theta) * glm::sin(phi),
			glm::sin(theta) * glm::sin(phi),
			glm::cos(phi)
		);

	}
	else {
		direction = glm::vec3(
			glm::cos(theta), 
			glm::sin(theta), 
			0
		);
	}

	//se almacenan los puntos junto a sus projecciones
	std::vector<ProjectedPoint> projections;
	for (Point* p : node->points) {
		ProjectedPoint projPoint;

		projPoint.point = p;
		projPoint.projection = glm::dot(projPoint.point->position, direction);
		
		projections.push_back(projPoint);
	}

	//se ordenan segun la projeccion (Ver ProjectedPoint)
	std::sort(projections.begin(), projections.end());

	//Se definen el punto deseado
	medianPoint = projections[(node->points.size()) / 2].point->position;
	medianProj = projections[(node->points.size()) / 2].projection;

	//colores aleatorios para pintar los puntos

	std::vector<Point*> rightPoints;
	std::vector<Point*> leftPoints;
	glm::vec3 rightColor = glm::vec3(
		static_cast <float> (rand()) /( static_cast <float> (RAND_MAX)),
		static_cast <float> (rand()) /( static_cast <float> (RAND_MAX)),
		static_cast <float> (rand()) /( static_cast <float> (RAND_MAX))
	);

	glm::vec3 leftColor = glm::vec3(
		static_cast <float> (rand()) /( static_cast <float> (RAND_MAX)),
		static_cast <float> (rand()) /( static_cast <float> (RAND_MAX)),
		static_cast <float> (rand()) /( static_cast <float> (RAND_MAX))
	);

	// se separan los puntos en 2 conjuntos para cada nodo
	//los puntos mayores o iguales a la proyeccion media van a derecha
	for( auto element : projections) {
		if(element.projection >= medianProj) {
			rightPoints.push_back(element.point);
			element.point->SetColor(rightColor);
			continue;
		}

		leftPoints.push_back(element.point);
		element.point->SetColor(leftColor);
	}

	//se almacenan los valores
	node->right->points = rightPoints;
	node->left->points = leftPoints;
	node->direction = direction;
	node->medianPoint = medianPoint;
	node->medianProj = medianProj;

	//! NOTA PARA EL PROFESOR
	// El código comentado en la parte inferior es usado para dibujar el hiperplano 
	// lo comentamos porque cuando existen demasiadas particiones el ver las lineas puede ser muy confuso
	// En 3D directamente se hace imposible ver la ubicación de los puntos
	// En caso desee ver las rectas descomente todo el siguiente código y vuelva a compilar el proyecto

	// Point* line =  new Point("Line", parent);
	// line->position = glm::vec3(medianPoint.x, medianPoint.y, 0);

	// if(is3D){
	// 	line->RotateEuler(glm::vec3(
	// 		0,
	// 		-1 * phi * 180 /glm::pi<float>(), 
	// 		theta * 180 /glm::pi<float>()));
	// 	line->scale = glm::vec3(0.05, boundary * 4, boundary * 4);
	// }

	// else {
	// 	line->RotateEuler(glm::vec3(0, 0, (theta * 180 /glm::pi<float>()) - 90 ));
	// 	line->scale = glm::vec3(boundary * 5, 0.05, 0.1);
	// }
	// line->SetColor(rightColor);
}