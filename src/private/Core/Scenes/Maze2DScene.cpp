#include "Core/Scenes/Maze2DScene.h"
#include "Core/Objects/SquareObject.h"
#include "Core/Objects/Maze.h"

Maze2DScene::Maze2DScene() {

	Maze* maze = new Maze(nullptr);
	objects.push_back(maze);
}