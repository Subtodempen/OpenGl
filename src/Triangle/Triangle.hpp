#pragma once 

#include "../CoreGl/GlWrapper.hpp"
#include "../ShaderProgram/ShaderProgram.hpp" 

#include <array>
#include <cmath>

class OpenGlTriangle : public CoreOpenGlWrapper {
	public:
		OpenGlTriangle(); 
		~OpenGlTriangle() = default;

		void drawTriangle(std::array<float, 3 * 3> vertices);// A triangle has 3 points each described by a vec3
		void setShaderProgram(ShaderProgram* program);

	private:
		unsigned int _VBO;
		unsigned int _VAO;
		ShaderProgram* _shaderProgram;

		void initVBO(); // stores vbo in memory
		void storeVBOData(float verticesArray[]);
		void createVBOattributes();

		void initVAO();
		void bindVAO();

		//void inputLogic() override;
		void renderLogic() override;
};