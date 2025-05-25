#include "Game/Scenes/HamSandwichTreeScene.h"

#include <Game/Objects/HamSandwichTree/Point.h>

HamSandwichTreeScene::HamSandwichTreeScene() {
    // glm::vec2 pointsPositions[] = {
    //     glm::vec2(0, 0),
    // };
    //
    // for (auto points_position : pointsPositions) {
    //     //Instantiate points in the declared position
    // }

    auto point1 =  Point(
        "Point1",
        nullptr,
        this);
	point1.position = glm::vec3(0, 0, 0);
}
