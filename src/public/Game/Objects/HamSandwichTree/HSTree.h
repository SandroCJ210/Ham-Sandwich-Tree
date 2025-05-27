#pragma once	
#include <Core/Objects/AObject.h>

class HSTreeComponent;

class HSTree : public AObject {
private:
	HSTreeComponent* hSTreeComponent;

public:
	HSTree(
		bool is3D,
		int quantity,
		float boundary,
		const std::string &_name, 
		AObject* _parent = nullptr, 
		ASceneController* _scene = nullptr
	);

	HSTreeComponent* GetHSTreeComponent() const { return hSTreeComponent; }
};