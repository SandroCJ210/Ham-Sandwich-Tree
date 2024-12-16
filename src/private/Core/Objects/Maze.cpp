#include "Core/Objects/Maze.h"
#include "Core/Components/Maze2D/MazeGeneratorComponent.h"

Maze::Maze(AObject* parent, std::string name) : AObject(parent, name) {
	mazeGeneratorComponent = dynamic_cast<MazeGeneratorComponent*>(AddComponent(new MazeGeneratorComponent(this)));
}

Maze::~Maze() {
	delete mazeGeneratorComponent;
}

