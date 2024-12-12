#pragma once
#include <string>

#include "Core/Objects/AObject.h"

class MazeGeneratorComponent;

class Maze : public AObject {
public:
	Maze(AObject* parent, std::string name);
	~Maze();
	
private:
	MazeGeneratorComponent* mazeGeneratorComponent;

public:
	MazeGeneratorComponent* GetMazeGeneratorComponent() const { return mazeGeneratorComponent; };
};