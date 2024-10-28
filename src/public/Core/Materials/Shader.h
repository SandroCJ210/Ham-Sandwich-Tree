#pragma once

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Math/Vector3.h"

class Shader {
public:
	unsigned int ID;

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

	void SetVec3(const std::string &name, Vector3 value) {
		glUniform3f(glGetUniformLocation(ID, name.c_str()), value.x, value.y, value.z);
	}

    //agregar setTexture
    
};
