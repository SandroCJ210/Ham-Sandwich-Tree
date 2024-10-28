#include "graph.h"
#include <iostream>

//Edge goes first just because the type of implementation I've used

//Edge implementation
Edge::Edge() {
	nextEdge = nullptr;
	from = 0;
	to = 0;
	weight = 0;
};

Edge::Edge(int v1, int v2) {
	from = v1;
	to = v2;
	weight = 0;
	nextEdge = nullptr;
}

Edge::Edge(int v1, int v2, int weight) : Edge::Edge(v1, v2) {
	weight = weight;
}

Edge::~Edge() {
};

//Node implementation
Node::Node() {
	ID = -1;
	distanceToRoot = -1;
	nodeData = 0;
	nextNode = nullptr;
	conection = nullptr;
	tempData = false;
};

Node::Node(int ID) : Node::Node() {
	this->ID = ID;
};

Node::Node(int ID, int data) : Node::Node(ID) {
	this->nodeData = data;
};

Node::~Node() {
	ID = -1;
	distanceToRoot = -1;
	nodeData = 0;
	tempData = false;
	conection = nullptr;
	nextNode = nullptr;
};

//Graph implementation
Graph::Graph() {
	head = nullptr;
	nodeNumber = 0;
};

Graph::~Graph() {
	pNode graphHead = this->head;

	while (graphHead != nullptr) {
		pNode nodeToDelete = graphHead;
		DeleteNode(nodeToDelete->ID);
		graphHead = graphHead->nextNode;
	}
};

//Creates a new node with the ID given and inserts it in the graph
void Graph::InsertNode(int ID) {
	if(SearchNodeByID(ID)) {
		std::cout << "Node already exists" << std::endl;
		return;
	}
	pNode newNode;
	newNode = new Node(ID);

	newNode->nextNode = head;
	head = newNode;

	nodeNumber++;
	std::cout<< "Node inserted with ID: " << ID << std::endl;
};

//Deletes a node with the ID given
void Graph::DeleteNode(int ID) {
	pNode nodeToDelete = SearchNodeByID(ID);

	if(nodeToDelete == nullptr) {
		std::cout << "Node does not exist" << std::endl;
		return;
	}
	
	//Delete edges related to this node
	while(nodeToDelete->conection != nullptr) {
		DeleteEdge(nodeToDelete->ID, nodeToDelete->conection->to);
	}	

	//deleting the node
	pNode graphHead = head;

	if (graphHead->ID == ID) {
		head = head->nextNode;
		nodeToDelete->~Node();
		return;
	}

	while (head->nextNode != nodeToDelete) {
		head = head->nextNode;
	}

	head->nextNode = nodeToDelete->nextNode;
	nodeToDelete->~Node();
};

//Checks if a node with the ID given exists
bool Graph::ExistNode(int ID) {
	if(nodeNumber == 0) return false;
	if(ID < 0) return false;
	if(SearchNodeByID(ID)) return true;
	return false;
};

//Searches for a node with the ID given
pNode Graph::SearchNodeByID(int IDnode) {
	pNode graphHead;
	graphHead = head;

	while (graphHead != nullptr) {
		if (graphHead->ID == IDnode)
			return graphHead;
		graphHead = graphHead->nextNode;
	}

	return nullptr;

};

//Inserts an edge between two nodes with the IDs given
void Graph::InsertEdge(int IDx, int IDy) {

	if (IDx < 0 || IDy < 0) {
		std::cout << "Invalid ID" << std::endl;
		return;
	}

	if (IDx == IDy) {
		std::cout << "Can't insert an edge between the same node" << std::endl;
		return;
	}

	if (nodeNumber <= 1) {
		std::cout << "graph is empty or only have 1 Node" << std::endl;
		return;
	}

	pEdge newEdge;
	pEdge edgeHead;
	pNode nodeX = SearchNodeByID(IDx);
	pNode nodeY = SearchNodeByID(IDy);

	if (nodeX == nullptr || nodeY == nullptr) {
		std::cout << "one or both nodes do not exist in trying to insert Edge (" << IDx << ", " << IDy << ")" << std::endl;
		return;
	}

	//Cheking for X
	edgeHead = nodeX->conection;
	while (edgeHead != nullptr) {
		if (edgeHead->to == IDy) {
			std::cout << "the Edge already exists" << std::endl;
			return;
		}
		edgeHead = edgeHead->nextEdge;
	};
	//Inserting for X
	newEdge = new Edge(IDx, IDy);
	newEdge->nextEdge = nodeX->conection;
	nodeX->conection = newEdge;

	//Cheking for Y
	edgeHead = nodeY->conection;
	while (edgeHead != nullptr) {
		if (edgeHead->to == IDx) {
			std::cout << "the Edge already exists" << std::endl;
			return;
		}
		edgeHead = edgeHead->nextEdge;
	};
	//Inserting for Y
	newEdge = new Edge(IDy, IDx);
	newEdge->nextEdge = nodeY->conection;
	nodeY->conection = newEdge;

	//Setting the distance to root
	if (nodeX->distanceToRoot == -1) { nodeX->distanceToRoot = nodeY->distanceToRoot + 1; }
	if (nodeY->distanceToRoot == -1) { nodeY->distanceToRoot = nodeX->distanceToRoot + 1; }
};

//Deletes an edge between two nodes with the IDs given
void Graph::DeleteEdge(int IDx, int IDy) {
	pEdge edgeToDelete;
	pEdge edgeHead;
	pNode nodeX = SearchNodeByID(IDx);
	pNode nodeY = SearchNodeByID(IDy);

	if (nodeNumber <= 1) {
		std::cout << "graph is empty or only have 1 Node" << std::endl;
		return;
	}

	if (!SearchNodeByID(IDx) || !SearchNodeByID(IDy)) {
		std::cout << "one or both nodes do not exist in trying to delete Edge (" << IDx << ", " << IDy << ")" << std::endl;
		return;
	}

	if (IDx == IDy) {
		std::cout << "Can't delete an edge between the same node" << std::endl;
		return;
	}

	//Deleting for X
	edgeHead = nodeX->conection;
	if (edgeHead->to == IDy) {
		nodeX->conection = edgeHead->nextEdge;
		edgeHead->~Edge();
	}
	else {
		while (edgeHead->nextEdge->to != IDy) {
			edgeHead = edgeHead->nextEdge;
		}
		edgeToDelete = edgeHead->nextEdge;
		edgeHead->nextEdge = edgeToDelete->nextEdge;
		edgeToDelete->~Edge();
	}

	//Deleting for Y
	edgeHead = nodeY->conection;
	if (edgeHead->to == IDx) {
		nodeY->conection = edgeHead->nextEdge;
		edgeHead->~Edge();
	}
	else {
		while (edgeHead->nextEdge->to != IDx) {
			edgeHead = edgeHead->nextEdge;
		}
		edgeToDelete = edgeHead->nextEdge;
		edgeHead->nextEdge = edgeToDelete->nextEdge;
		edgeToDelete->~Edge();
	}
};

//Prints the graph
void Graph::PrintGraph() {
	pNode graphHead;
	pEdge edgeHead;
	graphHead = head;

	if (nodeNumber == 0) std::cout << "Empty Graph" << std::endl;

	else {

		while (graphHead != nullptr) {
			std::cout << graphHead->ID << " conections: " << std::endl;
			edgeHead = graphHead->conection;

			while (edgeHead != nullptr) {
				std::cout << edgeHead->to << ", ";
				edgeHead = edgeHead->nextEdge;
			}

			std::cout << std::endl;
			graphHead = graphHead->nextNode;
		}
	}
};

//Checks if there is a circuit in the graph
bool Graph::ExistCircuit() {
	pNode graphHead = head;
	while(graphHead != nullptr) {
		graphHead->tempData = false;
		graphHead = graphHead->nextNode;
	}
	graphHead = head;
	while(graphHead != nullptr) {
		if(graphHead->tempData == false)
			if(SearchCircuitDFS(graphHead->ID, graphHead->ID))
				return true;
		graphHead = graphHead->nextNode;
	}

	return false;
};

//Checks if there is a circuit between two nodes
bool Graph::ExistCircuit(int IDx, int IDy) {
	pNode graphHead = head;
	while (graphHead != nullptr) {
		graphHead->tempData = false;
		graphHead = graphHead->nextNode;
	}
	return SearchCircuitDFS(IDx, IDy);
};

//Searches for a circuit using DFS
bool Graph::SearchCircuitDFS(int nodeID, int parentNodeID) {

	pNode Node = SearchNodeByID(nodeID);
	Node->tempData = true;

	pEdge Edge = Node->conection;

	while (Edge != nullptr) {

		if (SearchNodeByID(Edge->to)->tempData == false) {
			if (SearchCircuitDFS(Edge->to, parentNodeID))
				return true;
		}
		else if (parentNodeID == nodeID)
			return true;
		Edge = Edge->nextEdge;
	}

	return false;
};

int Graph::GetLongerLeaf() {
	pNode graphHead = head;
	int longerLeaf = -1;
	int longerDistance = 0;

	while (graphHead != nullptr) {
		if (graphHead->distanceToRoot > longerDistance) {
			longerDistance = graphHead->distanceToRoot;
			longerLeaf = graphHead->ID;
		}
		graphHead = graphHead->nextNode;
	}

	return longerLeaf;
};