#pragma once
#include <string>

#include "Core/Objects/AObject.h"

class MazeGeneratorComponent;

class Maze : public AObject {
public:
	Maze(const std::string &_name, AObject* _parent = nullptr, ASceneController* _scene = nullptr);
	~Maze();
	
private:
	MazeGeneratorComponent* mazeGeneratorComponent;

public:
	MazeGeneratorComponent* GetMazeGeneratorComponent() const { return mazeGeneratorComponent; };
};