#pragma once	
#include <Core/Objects/AObject.h>

class HSTreeComponent;

class HSTree : public AObject {
private:
	HSTreeComponent* hSTreeComponent;

public:
	/// @brief Instanciación de un objeto HSTree
	/// @param is3D Define si se quiere un resultado 3D
	/// @param quantity Define la cantidad de puntos que se quiere
	/// @param boundary Define la mitad de lado del cuadrado
	/// (o cubo en caso sea 3D) que serán los limites de la aparición de los puntos
	/// @param _name 
	/// @param _parent 
	/// @param _scene 
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