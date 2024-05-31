#pragma once 

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

class CoreOpenGlWrapper{
	public:
		CoreOpenGlWrapper();
		~CoreOpenGlWrapper();

		void createWindow(int width, int height, const std::string& windowName);
		void renderLoop();

	protected:	
		GLFWwindow* _window;

		void initContext();
		void loadGlud();

		void initViewPort();
		static void frameSizeCB(GLFWwindow* window, int width, int height);

		virtual void inputLogic() {};
		virtual void renderLogic() {};
		
		void ExitWithError(const std::string& error);	
};