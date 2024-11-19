#pragma once

struct Edge{
	int from;
	int to;
	int weight;
	Edge* nextEdge;

	Edge();
	Edge(int v1, int v2);
	Edge(int from, int data, int weight);

	~Edge();

};
typedef Edge* pEdge;


struct Node{
	int ID;
	int nodeData; //this is for knowing where the player is
	int distanceToRoot;
	bool tempData; //this is for checking algorithm stuff
	pEdge conection;
	Node* nextNode;

public:
	Node();
	Node(int ID);
	Node(int ID, int data);

	~Node();
};
typedef Node* pNode;


class Graph{
private:
	pNode head;
	int nodeNumber;

public:

	Graph();
	
	~Graph();
	
	void InsertNode(int ID);

	void DeleteNode(int ID);

	bool ExistNode(int ID);
	
	void InsertEdge(int IDx, int IDy);

	void DeleteEdge(int IDx, int IDy);

	pNode SearchNodeByID(int IDnode);
	
	void PrintGraph();

	bool ExistCircuit();

	bool ExistCircuit(int IDx, int IDy);

	bool SearchCircuitDFS(int nodeID, int parentNodeID);

	int GetLongerLeaf();

	int GetNodeNumber() const { return nodeNumber; };
};