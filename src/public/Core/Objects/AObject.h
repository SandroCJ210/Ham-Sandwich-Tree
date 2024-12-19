#pragma once
#include <vector>
#include <string>
#include "Core/Components/IComponent.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"

class AObject {
public:
	std::string name;

public:
	bool isEnabled = true;
	
	Vector3 position = {0, 0, 0};
	Vector3 rotation = {0, 0, 0};
	Vector3 scale = { 1, 1, 1 };

protected:
	Vector3 globalPosition = { 0, 0, 0 };
	Vector3 globalRotation = { 0, 0, 0 };
	Vector3 globalScale = { 1, 1, 1 };

public:
	std::vector<IComponent*> components;

	AObject* parent = nullptr;
	std::vector<AObject*> children;
	
	AObject(AObject* _parent, std::string name);
	virtual ~AObject();

	virtual void Awake();
	virtual void Start();
	virtual	void FixedUpdate();
	virtual void Update(double deltaTime);
	virtual void LateUpdate();
	virtual void End();

	IComponent* AddComponent(IComponent* component);

	template<typename T> 
	typename std::enable_if<std::is_base_of<IComponent, T>::value, T*>::type
	GetComponent() {
		for (IComponent* component : components) {
			if (T* t = dynamic_cast<T*>(component)) {
				return t;
			}
		}
		return nullptr;
	}

	void AddChild(AObject* child);

	// Getters and setters
	void SetGlobalPosition(Vector3 position);
	void SetGlobalRotation(Vector3 rotation);
	void SetGlobalScale(Vector3 scale);
	
	Vector3 GetGlobalPosition() const { return globalPosition; }
	Vector3 GetGlobalRotation() const { return globalRotation; }
	Vector3 GetGlobalScale() const { return globalScale; }
	Vector4 GetHomoPosition() const { return Vector4(position.x, position.y, position.z, 1); }

	// Static functions

	static AObject* FindObjectByName(std::string name);
};
