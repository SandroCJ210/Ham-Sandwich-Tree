#pragma once
#include <string>

#include "Core/Objects/AObject.h"

class MazeGeneratorComponent;

class Maze : public AObject {
public:
	Maze(AObject* parent, std::string name);
	~Maze();
	//void Start() override;
	//void Update() override;
	//void LateUpdate() override;
	//void End() override;
private:
	MazeGeneratorComponent* mazeGeneratorComponent;

public:
	MazeGeneratorComponent* GetMazeGeneratorComponent() const { return mazeGeneratorComponent; };
};