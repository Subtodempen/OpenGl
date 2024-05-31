#include "GlWrapper.hpp"


CoreOpenGlWrapper::CoreOpenGlWrapper(){
	_window = nullptr;
	glfwInit();
}


CoreOpenGlWrapper::~CoreOpenGlWrapper(){
  glfwTerminate();
}


void CoreOpenGlWrapper::renderLoop(){
	while(!glfwWindowShouldClose(_window)){
		inputLogic();
		renderLogic();

    glfwSwapBuffers(_window); //updates
    glfwPollEvents();  
  }
}


void CoreOpenGlWrapper::createWindow(int width, int height, const std::string& windowName){
	_window = glfwCreateWindow(300, 300, windowName.c_str(), NULL, NULL);

 	if(_window == NULL)
 		ExitWithError("Can not open window");
 	
 	initContext();
 	loadGlud();
 	initViewPort();
}

void CoreOpenGlWrapper::initContext(){
	glfwMakeContextCurrent(_window);
}

void CoreOpenGlWrapper::loadGlud(){
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		ExitWithError("Can not init Glud");
}

void CoreOpenGlWrapper::initViewPort(){
 	glViewport(0, 0, 300, 300);
 	glfwSetFramebufferSizeCallback(_window, &CoreOpenGlWrapper::frameSizeCB);
}

void CoreOpenGlWrapper::frameSizeCB(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}


void CoreOpenGlWrapper::ExitWithError(const std::string& error){
	std::cerr<<error; 

	glfwTerminate(); // change just to exit
}