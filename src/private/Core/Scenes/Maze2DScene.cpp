#include "Core/Scenes/Maze2DScene.h"
#include "Core/Objects/SquareObject.h"
#include "Core/Objects/Maze.h"
#include "Core/Objects/Player.h"

Maze2DScene::Maze2DScene() {

	Maze* maze = new Maze(nullptr, "Maze");
	objects.push_back(maze);

	Player* player = new Player(nullptr, "Player");
	objects.push_back(player);
}