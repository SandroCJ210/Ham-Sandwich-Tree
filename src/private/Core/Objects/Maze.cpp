#include "Core/Objects/Maze.h"
#include "Core/Components/MazeGeneratorComponent.h"

Maze::Maze(AObject* parent) : AObject(parent) {
	AddComponent(new MazeGeneratorComponent(this));
}

Maze::~Maze() {
}

