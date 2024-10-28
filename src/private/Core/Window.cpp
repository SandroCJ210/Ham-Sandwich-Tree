#include "Core/Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Core/Objects/SceneController.h"
#include "Core/Objects/TestObject.h"

Window::Window():Singleton(){
}


void Window::Start() {
	assetsFolder = "../Assets";
	//SceneController::GetInstance().objects.push_back(new TestObject());
	std::cout<< "Window Configuration \n";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Maze", nullptr, nullptr);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	});
}

void Window::Update() {
	while (!glfwWindowShouldClose(glfwGetCurrentContext())) {
		ProcessFrame(glfwGetCurrentContext());
		glfwSwapBuffers(glfwGetCurrentContext());
		glfwPollEvents();
	}
}

void Window::End() {
	glfwTerminate();
}


void Window::Excecute() {
	Start();
	Update();
	End();
}

void Window::ProcessFrame(GLFWwindow* window) {
	if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
	}
	
	//SceneController::GetInstance().Update();
	//TODO
}