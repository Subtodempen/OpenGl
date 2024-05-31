#include "ShaderProgram.hpp"


void ShaderProgram::initProgram(){
	_shaderProgramID = glCreateProgram();
}


void ShaderProgram::addShader(std::unique_ptr<Shader> smartShader){
	_shaderVec.push_back(std::move(smartShader));
 	
 	glAttachShader(_shaderProgramID, _shaderVec.back()->getShaderID());
}


void ShaderProgram::linkProgram(){
	char infoLog[512];
	int success;

	glLinkProgram(_shaderProgramID);
	glGetProgramiv(_shaderProgramID, GL_LINK_STATUS, &success);
	
	if(!success){
		glGetProgramInfoLog(_shaderProgramID, 512, NULL, infoLog);
		throw std::runtime_error(infoLog);
	}
}

void ShaderProgram::useProgram(){
	glUseProgram(_shaderProgramID);
}


void ShaderProgram::setUniform4f(const std::string& name, 
	float num1, 
	float num2, 
	float num3, 
	float num4){

	int uniformLocation = glGetUniformLocation(_shaderProgramID, name.c_str());

	if(uniformLocation == -1)
		throw std::runtime_error("Name not found in shader program");

	glUniform4f(uniformLocation, 
		num1, 
		num2, 
		num3, 
		num4);
}


unsigned int ShaderProgram::getShaderProgramID(){
	return _shaderProgramID;
}