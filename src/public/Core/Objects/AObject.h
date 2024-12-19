#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include "Core/Components/IComponent.h"
#include "Core/Render/Color.h"

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
	void SetGlobalPosition(glm::vec3 position);
	void SetGlobalRotation(glm::vec3 rotation);
	void SetGlobalScale(glm::vec3 scale);
	
	glm::vec3 GetGlobalPosition() const { return globalPosition; }
	glm::vec3 GetGlobalRotation() const { return globalRotation; }
	glm::vec3 GetGlobalScale() const { return globalScale; }
	glm::vec4 GetHomoPosition() const { return glm::vec4(position.x, position.y, position.z, 1); }

	// Static functions

	static AObject* FindObjectByName(std::string name);
};
