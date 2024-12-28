#include "Game/Objects/Maze.h"
#include "Game/Components/MazeGeneratorComponent.h"

Maze::Maze(AObject* parent, std::string name) : AObject(parent, name) {
	mazeGeneratorComponent = dynamic_cast<MazeGeneratorComponent*>(AddComponent(new MazeGeneratorComponent(this)));
	// rotation = glm::quat(1.0f, 0, 1.0f, 1.0f);
}

Maze::~Maze() {
	delete mazeGeneratorComponent;
}

