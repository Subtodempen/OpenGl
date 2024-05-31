#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <memory>
#include <stdexcept>

#include "../Shader/Shader.hpp"

class ShaderProgram{
	public:
		ShaderProgram() = default;
		~ShaderProgram() = default;

		void initProgram();
		void addShader(std::unique_ptr<Shader> smartShader);
		void linkProgram();
		void useProgram();

		void setUniform4f(const std::string& name, 
			float num1, 
			float num2, 
			float num3, 
			float num4);

		unsigned int getShaderProgramID();
	
	private:
		unsigned int _shaderProgramID;
		std::vector<std::unique_ptr<Shader>> _shaderVec;
};