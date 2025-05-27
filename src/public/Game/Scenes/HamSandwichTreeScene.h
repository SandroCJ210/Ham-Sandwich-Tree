#pragma once
#include <Core/Scenes/ASceneController.h>

class HamSandwichTreeScene : public ASceneController {
public:
	HamSandwichTreeScene();
	~HamSandwichTreeScene() override = default;

private:
	void SetBasicComponents2D();
	void SetBasicComponents3D();
};