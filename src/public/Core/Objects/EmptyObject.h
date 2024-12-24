#pragma once
#include "AObject.h"

class EmptyObject : public AObject {
public:
	EmptyObject(AObject* parent, std::string name);
};
