#include "Core/Objects/TestObject.h"

#include "Core/Components/RenderComponent.h"

TestObject::TestObject() {
	addComponent(new RenderComponent(this));
}
