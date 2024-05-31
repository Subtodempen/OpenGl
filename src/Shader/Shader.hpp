#pragma once 

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <string>

class Shader{
	public:
		Shader(const std::string& shaderCode, GLenum shaderType);
		~Shader();

		void initShader() noexcept;
		void compileShader();

		unsigned int getShaderID() const;
		GLenum getShaderType() const;
		void setShaderType(GLenum type);
	
	private:
		unsigned int _shaderID;
		std::string _shaderCode; 
		GLenum _shaderType;
};