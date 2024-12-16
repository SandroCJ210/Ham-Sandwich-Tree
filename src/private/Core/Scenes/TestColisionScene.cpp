#include "Core/Scenes/TestColisionScene.h"

#include <iostream>

#include "Core/Global.h"
#include "Core/Components/Render/RenderComponent.h"
#include "Core/Components/Input/FollowMouseComponent.h"
#include "Core/Components/Input/InputComponent.h"
#include "Core/Components/Maze2D/MovementComponent.h"
#include "Core/Components/Physics/RigidbodyComponent.h"
#include "Core/Components/Physics/SquareColliderComponent.h"
#include "Core/Objects/SquareObject.h"
#include "Core/Render/Color.h"
#include "Core/Render/Render.h"

TestColisionScene::TestColisionScene() {
	
	SquareObject* testSquare = new SquareObject(nullptr, "squareMouse");
	testSquare->GetRenderComponent()->enableRender = false;
	// testSquare->AddComponent(new FollowMouseComponent(testSquare));
	testSquare->AddComponent(new RigidbodyComponent(testSquare));
	testSquare->AddComponent(new InputComponent(testSquare));
	MovementComponent* movement =  dynamic_cast<MovementComponent*>(
		testSquare->AddComponent(new MovementComponent(testSquare))
		);
	testSquare->position = Vector3(-0.5, 0, 0);
	testSquare->scale = Vector3(0.3);
	movement->SetSpeed(3);
	// movement->SetDirection(Vector2(1, 0));
	AddObject(testSquare);

	SquareObject* staticSquare = new SquareObject(nullptr, "staticSquare");
	staticSquare->GetRenderComponent()->enableRender = false;
	// staticSquare->GetColliderComponent()->isTrigger = true;
	// staticSquare->AddComponent(new FollowMouseComponent(staticSquare));
	staticSquare->scale = Vector3(0.5);
	AddObject(staticSquare);

	SquareObject* sumSquare = new SquareObject(nullptr, "sumSquare");
	sumSquare->GetRenderComponent()->enableRender = false;
	sumSquare->GetColliderComponent()->isTrigger = true;
	sumSquare->position = Vector3(staticSquare->GetGlobalPosition());
	sumSquare->scale = staticSquare->scale + testSquare->scale ;
	AddObject(sumSquare);

	// SquareObject* resultSquare = new SquareObject(nullptr, "resultSquare");
	// resultSquare->GetRenderComponent()->enableRender = false;
	// resultSquare->scale = Vector3(0.3);
	// AddObject(resultSquare);

	// SquareObject* startSquare = new SquareObject(nullptr, "startSquare");
	// startSquare->GetRenderComponent()->enableRender = false;
	// startSquare->position = Vector2(1.5, 1.7);
	// startSquare->scale = Vector3(0.3);
	// AddObject(startSquare);
	
}

void TestColisionScene::Update(double deltaTime) {
	// std::cout<<deltaTime<<'\n';

	SquareObject* testSquare = dynamic_cast<SquareObject*>(objects[0]);
	RigidbodyComponent* rbTestSquare = nullptr;
	for (IComponent* component : testSquare->components) {
		rbTestSquare = dynamic_cast<RigidbodyComponent*>(component);
		if (rbTestSquare != nullptr) {
			break;
		}
	}
	
	Render::GetInstance().DrawLineSegment(
		testSquare->GetGlobalPosition(),
		testSquare->GetGlobalPosition() + rbTestSquare->velocity * Global::FIXED_DELTA_TIME,
		Color::RED
		);
	
	ASceneController::Update(deltaTime);

}