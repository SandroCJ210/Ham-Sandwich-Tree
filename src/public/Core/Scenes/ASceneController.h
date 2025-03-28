#pragma once
#include <vector>
#include <Core/Components/Render/Lights/LightComponent.h>

#include "Core/Objects/AObject.h"

class ASceneController {

	friend class AObject;

private:
	// bunch of stuff for calculating the delta time and physics time offset
	// (this is used for know when to exceute the physics)
	double current;
	double previous;
	double physicsTimeOffset = 0.0;
	
public:
	/**
	 * @brief The list of objects in the scene
	 */
	std::vector<AObject*> objects = std::vector<AObject*>();


	/**
	 * @brief Active light source
	 */
	//TODO: Implement multiple source lights
	LightComponent* lightSource = nullptr;
	
	ASceneController();
	virtual ~ASceneController();

	/**
	 * Excecute the scene general update
	 */
	virtual void SceneUpdate();

	/**
	 * @brief This method is called when the scene is created before the start
	 * This is the first method to be called
	 */
	virtual void Awake();

	/**
	 * @brief This method is called when the scene is created after the awake
	 */
	virtual void Start();

	/**
	 * @brief This method is for the physics update and excecuted in a fixed time
	 */
	virtual void FixedUpdate();

	/**
	 * @brief This method is called every frame
	 * @param deltaTime The	time between frames
	 */
	virtual void Update(double deltaTime);

	/**
	 * @brief This method is called after the update
	 * Is used mainly for the rendering
	 */
	virtual void LateUpdate();

	/**
	 * This method is called when the scene is destroyed
	 */
	virtual void End();

protected:
	/**
	 * Adds an object to this scene
	 * @param object The object to add
	 */
	void AddObject(AObject* object);
};