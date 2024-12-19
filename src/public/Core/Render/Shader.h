#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <iostream>


class Shader {
public:
	unsigned int ID;

private:
	std::string vertexPath;
	std::string fragmentPath;

public:
	Shader(const std::string vertexPath, const std::string fragmentPath);
	
	/*
	 *Use/activate the shader program 
	 */
	void Use() const {
		glUseProgram(ID);
	}
	
	/*
	 *Set a bool uniform giving a name
	 */
	void SetBool(const std::string &name, bool value) const{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}

	/*
	 *Set a int uniform giving a name
	 */
    void SetInt(const std::string &name, int value) const{
    	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

	/*
	 *Set a float uniform giving a name
	 */
    void SetFloat(const std::string &name, float value) const{
    	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

	void SetVector3(const std::string &name, glm::vec3 value) {
		int location = glGetUniformLocation(ID, name.c_str());
		glUniform3f(location, value.x, value.y, value.z);
	}

    //agregar setTexture
    

public:
	bool CompareFiles(const std::string vertexPath, const std::string fragmentPath) const {
		return this->vertexPath == vertexPath && this->fragmentPath == fragmentPath;
	}

	bool operator==(const Shader& other) const {
		return this->ID == other.ID;
	}
};
