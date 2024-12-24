#include "Core/Render/Render.h"

#include <glad/glad.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

#include "Core/Render/Shader.h"
#include "Core/Materials/GizmosMaterial.h"
#include "Core/Global.h"
#include "Core/Components/Render/CameraComponent.h"

Render::Render() {

	gizmosMaterial = new GizmosMaterial();

	InitQuad();
	InitLine();
}

Render::~Render() {

}

Shader* Render::CreateShader(const std::string vertexPath, const std::string fragmentPath) {

	for (Shader* shader : shaders) {
		if (shader->CompareFiles(vertexPath, fragmentPath)) {
			return shader;
		}
	}

	Shader* newShader = new Shader(vertexPath, fragmentPath);
	shaders.push_back(newShader);
	return newShader;
}

glm::vec3 Render::TransformWorldToScreen(glm::vec3 worldScale) {
	return glm::vec3(
		(Global::METER / Global::SCREEN_FORMAT) * worldScale.x,
		Global::METER * worldScale.y, 0);
}

void Render::InitLine() {
	glGenVertexArrays(1, &VAO_line);

	glBindVertexArray(VAO_line);

	glGenBuffers(1, &VBO_line);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_line);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Render::InitQuad() {

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	glGenVertexArrays(1, &VAO_quad);

	glBindVertexArray(VAO_quad);

	glGenBuffers(1, &VBO_quad);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_quad);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertices, GL_DYNAMIC_DRAW);

	glGenBuffers(1, &EBO_quad);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_quad);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

}

void Render::DrawLineSegment(glm::vec3 start, glm::vec3 end, glm::vec3 color) {
	if (currentCamera == nullptr) return;
	
	gizmosMaterial->SetColor(color);

	gizmosMaterial->shader->Use();
	gizmosMaterial->SetColorUniform();
	
	gizmosMaterial->shader->SetMatrix4("_model", glm::mat4(1.0f));
	gizmosMaterial->shader->SetMatrix4("_view", currentCamera->GetViewMatrix());
	gizmosMaterial->shader->SetMatrix4("_projection", currentCamera->GetProjectionMatrix());

	float vertices[] = {
		(float)start.x, (float)start.y, (float)start.z,
		(float)end.x, (float)end.y, (float)end.z
	};

	glLineWidth(1);

	glBindVertexArray(VAO_line);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_line);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 6 * sizeof(float), vertices);

	glDrawArrays(GL_LINES, 0, 2);

	glBindVertexArray(0);
}

void Render::DrawQuad(glm::vec3 center, glm::vec3 scale, Shader* shader, glm::vec3 color) {
	if (currentCamera == nullptr) return;
	// glm::vec3 scaleScreen = TransformWorldToScreen(scale);
	// glm::vec3 centerScreen = TransformWorldToScreen(center);

	//Model matrix generation
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, center);
	model = glm::scale(model, scale);
	
	shader->Use();
	shader->SetVector3("_color", color);
	shader->SetMatrix4("_model", model);
	shader->SetMatrix4("_view", currentCamera->GetViewMatrix());
	shader->SetMatrix4("_projection", currentCamera->GetProjectionMatrix());

	glBindVertexArray(VAO_quad);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void Render::DrawQuadLine(glm::vec3 center, glm::vec3 scale, glm::vec3 color) {

	glm::vec3 points[] = {
		glm::vec3(center.x - scale.x / 2, center.y - scale.y / 2, 0), //bottom left
		glm::vec3(center.x + scale.x / 2, center.y - scale.y / 2, 0), //bottom right
		glm::vec3(center.x + scale.x / 2, center.y + scale.y / 2, 0), //top right
		glm::vec3(center.x - scale.x / 2, center.y + scale.y / 2, 0), //top left
	};

	DrawLineSegment(points[0], points[1], color);
	DrawLineSegment(points[1], points[2], color);
	DrawLineSegment(points[2], points[3], color);
	DrawLineSegment(points[3], points[0], color);

}

void Render::SetCurrentCamera(CameraComponent* camera) {
	currentCamera = camera;
}