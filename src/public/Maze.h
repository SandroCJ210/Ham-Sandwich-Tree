#pragma once
#include "graph.h"


class Maze {
private:
	Graph mazeGraph;
	int size;
	long seed;
	int startID;
	int endID;

public:
	Maze();
	Maze(int size);
	Maze(int size, long seed);

	~Maze();

	void GenerateMaze();
	void PrintMaze();
	void DrawMaze();

	int GetSize() const { return size; }
	void SetSize(int size) { this->size = size; }
	long GetSeed() const { return seed; }
	void SetSeed(long seed) { this->seed = seed; }
};

