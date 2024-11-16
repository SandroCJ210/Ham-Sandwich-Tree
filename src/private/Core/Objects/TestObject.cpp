#include "Core/Objects/SquareObject.h"

#include "Core/Components/RenderComponent.h"
#include "Core/Components/TestMovementComponent.h"

SquareObject::SquareObject() {
	addComponent(new RenderComponent(this));
	//addComponent(new TestMovementComponent(this));
}
