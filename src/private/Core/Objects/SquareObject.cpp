#include "Core/Objects/SquareObject.h"

#include "Core/Components/RenderComponent.h"
#include "Core/Components/TestMovementComponent.h"

SquareObject::SquareObject(AObject* parent, std::string name) : AObject(parent, name){
	renderComponent = dynamic_cast<RenderComponent*>( AddComponent(new RenderComponent(this)) );
}
