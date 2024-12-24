#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include "Core/Components/IComponent.h"

class AObject {
public:
	std::string name;

public:
	bool isEnabled = true;
	
	glm::vec3 position = {0, 0, 0};
	glm::vec3 rotation = {0, 0, 0};
	glm::vec3 scale = { 1, 1, 1 };

protected:
	glm::vec3 globalPosition = { 0, 0, 0 };
	glm::vec3 globalRotation = { 0, 0, 0 };
	glm::vec3 globalScale = { 1, 1, 1 };

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
	void SetWorldPosition(glm::vec3 position);
	void SetWorldRotation(glm::vec3 rotation);
	void SetWorldScale(glm::vec3 scale);
	
	glm::vec3 GetWorldPosition() const { return globalPosition; }
	glm::vec3 GetWorldRotation() const { return globalRotation; }
	glm::vec3 GetWorldScale() const { return globalScale; }

	// Static functions

	static AObject* FindObjectByName(std::string name);
};
