#include <Game/Objects/HamSandwichTree/HSTree.h>
#include <Game/Components/HamSandwichTree/HSTreeComponent.h>

HSTree::HSTree(
	bool is3D, 
	int quantity,
	float boundary,
	const std::string& _name, 
	AObject* _parent, 
	ASceneController* _scene)
	: AObject(_name, _parent, _scene) {

	hSTreeComponent = dynamic_cast<HSTreeComponent*>( 
		AddComponent(new HSTreeComponent(is3D, quantity, boundary, this))
	);
	
}