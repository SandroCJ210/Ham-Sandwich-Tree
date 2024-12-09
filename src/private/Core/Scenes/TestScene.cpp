#include "Core/Scenes/TestScene.h"
#include "Core/Objects/SquareObject.h"
#include "Core/Components/RenderComponent.h"
#include "Core/Materials/BaseMaterial.h"

TestScene::TestScene() {
	SquareObject* square = new SquareObject(nullptr, "Square");
	objects.push_back(square);

	SquareObject* square2 = new SquareObject(nullptr, "Square");
	square2->position = Vector3(0.5f, 0.5f, 0);
	BaseMaterial* square2Material = dynamic_cast<BaseMaterial*>(square2->GetRenderComponent()->material);
	square2Material->color = Vector3(1, 0, 0);

	objects.push_back(square2);
}