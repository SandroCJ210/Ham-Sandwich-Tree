#pragma once


/**
 * @brief This struct represents an edge in a graph
 */
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

/**
 * @brief This struct represents a node in a graph
 */
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


/**
 * @brief This class represents a no-directed graph
 */
class Graph{
private:
	pNode head;
	int nodeNumber;

public:

	Graph();
	
	~Graph();
	
	/**
	 * @brief This method inserts a node in the graph
	 * @param ID The ID of the node to insert
	 */
	void InsertNode(int ID);

	/**
	 * @brief This method deletes a node in the graph
	 * @param ID The ID of the node to delete
	 */
	void DeleteNode(int ID);

	/**
	 * @brief This method checks if a node exists in the graph
	 * @param ID The ID of the node to check
	 * @return True if the node exists, false otherwise
	 */
	bool ExistNode(int ID);

	/**
	 * @brief This method inserts an edge in the graph
	 * @param IDx The ID of the first node
	 * @param IDy The ID of the second node
	 */
	void InsertEdge(int IDx, int IDy);

	/**
	 * @brief This method deletes an edge in the graph
	 * @param IDx The ID of the first node
	 * @param IDy The ID of the second node
	 */
	void DeleteEdge(int IDx, int IDy);

	/**
	 * @brief This method searches a node in the graph
	 * @param IDnode The ID of the node to search
	 * @return The node if it exists, nullptr otherwise
	 */
	pNode SearchNodeByID(int IDnode);

	/**
	 * @brief This method prints the graph in the console
	 */
	void PrintGraph();

	/**
	 * This method checks if the graph has a circuit
	 * @return True if the graph has a circuit, false otherwise
	 */
	bool ExistCircuit();

	/**
	 * @brief Searches for a circuit between two nodes
	 * @param IDx ID of the first node
	 * @param IDy ID of the second node
	 * @return True	if there is a circuit between the two nodes, false otherwise
	 */
	bool ExistCircuit(int IDx, int IDy);

private:
	/**
	 * @brief searches for a circuit using DFS
	 * @param nodeID the actual node ID
	 * @param parentNodeID The parent node ID
	 * @return True if there is a circuit, false otherwise
	 */
	bool SearchCircuitDFS(int nodeID, int parentNodeID);
	
public:
	/**
	 * This method searches the longest leaf in the graph assuming that the graph is a tree
	 * @return The ID of the longer leaf in the graph
	 */
	int GetLongerLeaf();

	/**
	 * 
	 * @return The number of nodes in the graph
	 */
	int GetNodeNumber() const { return nodeNumber; }
};