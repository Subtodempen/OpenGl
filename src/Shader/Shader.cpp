#include "Shader.hpp"

Shader::Shader(const std::string& shaderCode, GLenum shaderType): 
_shaderCode(shaderCode),
_shaderType(shaderType) {}

Shader::~Shader(){
	glDeleteShader(_shaderID);
}


void Shader::initShader() noexcept{
	const char* shaderCodePtr = _shaderCode.c_str(); 
	
	_shaderID = glCreateShader(_shaderType); // segfault
	glShaderSource(_shaderID, 1, &shaderCodePtr, NULL);
}

void Shader::compileShader(){
	char infoLog[512];
	int success;

	glCompileShader(_shaderID);
	glGetShaderiv(_shaderID, GL_COMPILE_STATUS, &success);

	if(!success){
		glGetShaderInfoLog(_shaderID, 512, NULL, infoLog);
		throw std::runtime_error(infoLog);
	}
}


unsigned int Shader::getShaderID() const{
	return _shaderID;
}

GLenum Shader::getShaderType() const{
	return _shaderType;
}

void Shader::setShaderType(GLenum type){
	_shaderType = type;
}
