#pragma once

#include <Util/Singleton.h>
#include <Core/Scenes/ASceneController.h>

/**
 * @brief This class represents the window of the game
 */
class Window : public Singleton<Window>{

private:
	ASceneController* actualScene;

public:
	Window();
	
	/**
	 * This method execute the initialization, loop and end of the game
	 */
	void Execute();

	/**
	 * @brief This method adds an object to the actual scene
	 * @param object The object to add
	 */
	void AddObjectToScene(AObject* object);

private:
	/**
	 * The initialization of the window
	 */
	void Start();
	/**
	 * The loop of the game
	 */
	void Update();
	/**
	 * The end of the game
	 */
	void End();

	/**
	 * @brief This method processes the frame of the window
	 * @param window The window to process
	 */
	void ProcessFrame(struct GLFWwindow* window);

public:
	/**
	 * @brief This method sets the actual scene to execute
	 * @param scene	The scene to set
	 */
	void SetActualScene(ASceneController* scene) { actualScene = scene; }

	/**
	 * 
	 * @return The actual scene
	 */
	ASceneController* GetActualScene() const { return actualScene; }
};
template class Singleton<Window>;
