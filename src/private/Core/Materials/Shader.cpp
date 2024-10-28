#include "Core/Materials/Shader.h"

#include <iostream>
#include <fstream>

Shader::Shader (const std::string vertexPath, const std::string fragmentPath){
	// 1 Reading data from the path
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	//* ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try{
    	//opening files
    	vShaderFile.open(vertexPath);
    	fShaderFile.open(fragmentPath);
    	std::stringstream vShaderStream, fShaderStream;

    	//Passing files to the stream
    	vShaderStream << vShaderFile.rdbuf();
    	fShaderStream << fShaderFile.rdbuf();

    	//Closing files
    	vShaderFile.close();
    	fShaderFile.close();

    	//converting stream to string
    	vertexCode = vShaderStream.str();
    	fragmentCode = fShaderStream.str();
    }
    catch(std::ifstream::failure e){
    	std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ\n";
    }
    //string to char pointer
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    
    //2 Constructing the shader program
    unsigned int vertex, fragment;
    int sucess;
    char infoLog[512];

    //vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &sucess);
    if(!sucess){
    	glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog <<"\n";
    }

    //fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &sucess);
    if(!sucess){
    	glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
    }

    //shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &sucess);
    if(!sucess){
    	glGetProgramInfoLog(ID, 512, NULL, infoLog);
    	std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << "\n";
    }

    //delete shaders
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


