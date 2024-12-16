#include "Core/Scenes/TestScene.h"
#include "Core/Objects/SquareObject.h"
#include "Core/Objects/Player.h"
#include "Core/Components/Render/RenderComponent.h"
#include "Core/Materials/BaseMaterial.h"

TestScene::TestScene() {
	Player* square = new Player(nullptr, "Square", nullptr);
	/*square->scale =Vector3(0.5, 0.5, 0.5);
	square->position = Vector3(-1, -1, 0);*/
	
	objects.push_back(square);

	SquareObject* square2 = new SquareObject(nullptr, "Square2");
	square2->position = Vector3(1, 1, 0);
	objects.push_back(square2);
}