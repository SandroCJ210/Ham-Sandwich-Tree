#include <Core/Objects/EmptyObject.h>
#include <Core/Scenes/ASceneController.h>

EmptyObject::EmptyObject(const std::string &_name, AObject* _parent, ASceneController* _scene)
	: AObject(_name, _parent, _scene) {
}