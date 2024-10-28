#include "Maze.h"

#include "Utility.h"
#include <iostream>
#include <random>
#include <vector>



Maze::Maze() {
	size = 3; //Default size of Maze
	seed = 0; //Default seed
	startID = -1;
	endID = -1;
};

Maze::Maze(int size) : Maze::Maze() {
	if(size < 3 || size %2 == 0) {
		std::cout << "Invalid size. Size must be an odd number greater than 4." << std::endl;
		return;
	}
	SetSize(size);
};

Maze::Maze(int size, long seed) : Maze::Maze(size) {
	SetSeed(seed);
};

Maze::~Maze() {
	mazeGraph.~Graph();
};

void Maze::GenerateMaze() {
	srand(seed);
	std::vector<int> posibleNextNodes;
	std::vector<int> notPosibleNextNodes;
	
	//Defining the root and the initial posibilities
	mazeGraph = Graph();
	mazeGraph.InsertNode(0);
	posibleNextNodes.push_back(1);
	posibleNextNodes.push_back(size-2);

	//Creating the maze
	do {
		//Selecting the next node
		int index = rand() % posibleNextNodes.size();
		int newNodeID = posibleNextNodes[index];
		posibleNextNodes.erase(posibleNextNodes.begin() + index);
		mazeGraph.InsertNode(newNodeID);
		if (newNodeID % (size - 2) != 0)		mazeGraph.InsertEdge(newNodeID - 1, newNodeID); 
		if ((newNodeID + 1) % (size - 2) != 0)	mazeGraph.InsertEdge(newNodeID + 1, newNodeID);	
		
		mazeGraph.InsertEdge(newNodeID + (size - 2), newNodeID);
		mazeGraph.InsertEdge(newNodeID - (size - 2), newNodeID);

		//checking circuits
		if (mazeGraph.ExistCircuit()) {
			mazeGraph.DeleteNode(newNodeID);
			notPosibleNextNodes.push_back(newNodeID);
			continue;
		}
		
		//Checking the next posibilities

		//right
		if (!Utility::FindInVector(posibleNextNodes, newNodeID + 1) &&
			!Utility::FindInVector(notPosibleNextNodes, newNodeID + 1) &&
			!mazeGraph.ExistNode(newNodeID + 1) && 
			(newNodeID + 1) % (size - 2) != 0) {
			
			posibleNextNodes.push_back(newNodeID + 1);
		}

		//left
		if (!Utility::FindInVector(posibleNextNodes, newNodeID - 1) &&
			!Utility::FindInVector(notPosibleNextNodes, newNodeID - 1) &&
			!mazeGraph.ExistNode(newNodeID - 1) && 
			newNodeID % (size - 2) != 0) {
			
			posibleNextNodes.push_back(newNodeID - 1);
		}

		//down
		if (!Utility::FindInVector(posibleNextNodes, newNodeID + (size - 2)) &&
			!Utility::FindInVector(notPosibleNextNodes, newNodeID + (size - 2)) &&
			(newNodeID + (size - 2)) < ((size - 2) * (size - 2) - 1) && 
			!mazeGraph.ExistNode(newNodeID + (size - 2))) {
			
			posibleNextNodes.push_back(newNodeID + (size - 2));
		}

		//up
		if (!Utility::FindInVector(posibleNextNodes, newNodeID - (size - 2)) &&
			!Utility::FindInVector(notPosibleNextNodes, newNodeID - (size - 2)) &&
			(newNodeID - (size - 2)) > 0 &&
			!mazeGraph.ExistNode(newNodeID - (size - 2))) {

			posibleNextNodes.push_back(newNodeID - (size - 2));
		}

	} while (posibleNextNodes.size() != 0);

	//Setting the start and end of the maze
	startID = 0;
	endID = mazeGraph.GetLongerLeaf();
};

void Maze::PrintMaze() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0 || i == size-1 || j == 0 || j == size-1) {
				std::cout << "#";
				continue;
			}

			int ID = (i - 1) * (size - 2) + (j - 1);
			if (mazeGraph.ExistNode(ID)) {
				if (ID == startID)		std::cout << "A";
				else if (ID == endID)	std::cout << "B";
				else					std::cout << " ";

				continue;
			}
			std::cout << "#";

		}

		std::cout << std::endl;
	}
};

void Maze::DrawMaze() {
	//TODO
};