#pragma once
#include "Core/Components/IComponent.h"
#include "Util/Graph.h"	
#include <string>

class Vector3;
class MazeGeneratorComponent : public IComponent {
private:
	Graph mazeGraph;
	int size;
	long seed;
	int startID;
	int endID;

public:
	MazeGeneratorComponent(AObject* parent);
	~MazeGeneratorComponent() override;
	void Start() override;

private:
	void GenerateMaze();
	void GenerateObjects();
	void PrintMaze();

	void InstantiateWall(std::string id, Vector3 objectPosition, Vector3 objectSize);

public:
	int GetSize() const { return size; }
	void SetSize(int size) { this->size = size; }
	long GetSeed() const { return seed; }
	void SetSeed(long seed) { this->seed = seed; }
};