#pragma once
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Core/Components/IComponent.h"

class AObject {
public:
	std::string name;

public:
	bool isEnabled = true;
	
	/**
	 * Local position
	 */
	glm::vec3 position = {0, 0, 0};

	/**
	 * Local rotation
	 */
	glm::quat rotationQuat = { 1, 0, 0, 0};

	/**
	 * Local scale
	 */
	glm::vec3 scale = { 1, 1, 1 };

protected:
	/**
	 * World position
	 */
	glm::vec3 worldPosition = { 0, 0, 0 };

	/**
	 * World rotation
	 */
	glm::quat worldRotation = { 1, 0, 0, 0 };

	/**
	 * World scale
	 */
	glm::vec3 worldScale = { 1, 1, 1 };

public:
	
	/**
	 * The components of the object.
	 */
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

	/**
	 * @brief Gets a component of the object.
	 * @tparam T The type of the component.
	 * @return The component of the object.
	 */
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

	/**
	 * @brief Rotates the object in the local space.
	 * @param rotation The quaternion to apply.
	 */
	void Rotate(glm::quat rotation);

	/**
	 * @brief Rotates the object in the local space.
	 * @param rotation The euler angles to apply.
	 */
	void RotateEuler(glm::vec3 rotation);

	glm::vec3 Forward();
	glm::vec3 Right();
	glm::vec3 Up();
	
	// Getters and setters
	void SetRotation(glm::quat rotation);
	void SetWorldPosition(glm::vec3 position);
	void SetWorldRotation(glm::quat rotation);
	void SetWorldScale(glm::vec3 scale);
	
	glm::vec3 GetWorldPosition()	const { return worldPosition; }
	glm::quat GetWorldRotation()	const { return glm::normalize(worldRotation); }
	glm::vec3 GetWorldScale()		const { return worldScale; }

	// Static functions

	/**
	 * @brief Finds an object in the scene by its name.
	 * @param name The name of the object.
	 * @return The object with the name.
	 */
	static AObject* FindObjectByName(std::string name);
};
