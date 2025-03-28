#pragma once
#include "AObject.h"

class EmptyObject : public AObject {
public:
	explicit EmptyObject(const std::string &_name, AObject* _parent = nullptr, ASceneController* _scene = nullptr);
};
