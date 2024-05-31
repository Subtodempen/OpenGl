#include "Triangle.hpp"


OpenGlTriangle::OpenGlTriangle(){
	_VBO = 0;
	_VAO = 0;
	_shaderProgram = nullptr;
}

void OpenGlTriangle::drawTriangle(std::array<float, 3 * 3> vertices){
	initVBO();
	initVAO();

	bindVAO();
	storeVBOData(vertices.data());
	createVBOattributes(); 		// VAO is binded so the attributes are rememberd? 
}


void OpenGlTriangle::initVBO(){
	glGenBuffers(1, &_VBO);
  	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
}

void OpenGlTriangle::initVAO(){
	glGenVertexArrays(1, &_VAO);  
}


void OpenGlTriangle::bindVAO(){
	glBindVertexArray(_VAO);
}

void OpenGlTriangle::storeVBOData(float verticesArray[]){
	glBufferData(GL_ARRAY_BUFFER, 9*sizeof(float), verticesArray, GL_STATIC_DRAW);
}

void OpenGlTriangle::createVBOattributes(){
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  	glEnableVertexAttribArray(0);  
}


void OpenGlTriangle::renderLogic(){
    if(_shaderProgram == nullptr)
    	ExitWithError("Can not run without SHADERS");

    _shaderProgram->useProgram();

    _shaderProgram->setUniform4f("name", std::sin(glfwGetTime()), 0.5f, std::cos(glfwGetTime()), std::tan(glfwGetTime()));

    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}


void OpenGlTriangle::setShaderProgram(ShaderProgram* program){
	_shaderProgram = program;
}
