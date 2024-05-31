#include <cstddef>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "CoreGl/GlWrapper.hpp"
#include "Triangle/Triangle.hpp"
#include "Shader/Shader.hpp"
#include "ShaderProgram/ShaderProgram.hpp"

#include <array>
#include <memory>

int main(){
 //CoreOpenGlWrapper gl;

  //gl.createWindow(100, 100, "hello");
  //gl.renderLoop();


  std::array<float, 9> verticies = {
    -0.5f, 0.0f, 0.0f,
    0.5f, 0.0f, 0.0f,
    0.0f, 0.5f, 0.0f
  };

  const std::string fragShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "uniform vec4 name;\n"
    "void main()\n"
    "{\n"
    " FragColor = name;\n"
    "}\n";
  
  const std::string vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n";


  OpenGlTriangle triangle;
  ShaderProgram shaderProgram;
  std::unique_ptr<Shader> fragShader = std::make_unique<Shader>(fragShaderSource, GL_FRAGMENT_SHADER);
  std::unique_ptr<Shader> vertexShader = std::make_unique<Shader>(vertexShaderSource, GL_VERTEX_SHADER);

  triangle.createWindow(100, 100, "Triangle");
  
  vertexShader->initShader();
  vertexShader->compileShader();

  fragShader->initShader();
  fragShader->compileShader();

  shaderProgram.initProgram();
  
  shaderProgram.addShader(std::move(vertexShader));
  shaderProgram.addShader(std::move(fragShader));
  
  shaderProgram.linkProgram();
  shaderProgram.useProgram();

  triangle.setShaderProgram(&shaderProgram);

  triangle.drawTriangle(verticies);
  triangle.renderLoop();
}

/*

void frameSizeCB(GLFWwindow* window, int width, int height);

void frameSizeCB(GLFWwindow* window, int width, int height){
  glViewport(0, 0, width, height);
}

int main(){

  glfwInit();
  GLFWwindow* window = glfwCreateWindow(300, 300, "TEST APP", NULL, NULL);

  if(window == NULL){
    std::cerr<<"Can not open window";
    
    glfwTerminate();
    return -1;
  }
  
  glfwMakeContextCurrent(window);
  
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  //handle veiw port
  glViewport(0, 0, 300, 300);
  glfwSetFramebufferSizeCallback(window, frameSizeCB);

  //handle triangle init
  //create vertex
  float vertices[] = {
    -1.0f, 0.0f, 0.0f, //bLeft
    0.0f, 0.0f, 0.0f, //bRight
    -0.5f, 1.0f, 0.0f, //Top
    
    0.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    0.5f, 1.0f, 0.0f
  };

  // bind it to memory (VBO)
  //create VBO
  unsigned int VBO;
  unsigned int VAO;
  glGenVertexArrays(1, &VAO);  
  
  glBindVertexArray(VAO);
  
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Create shaders for it
  const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  const char *fragShaderSource = 
    "#version 330 core\n"
    "out vec4 FragColor\n"
    "void main()\n"
    "{\n"
    " FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);\n"
    "}\0";
  unsigned int fragShader;
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(fragShader, 1, &fragShaderSource, NULL);
  glCompileShader(fragShader);

  //link shaders
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragShader);

  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);  
  // display triuangle
  
  //glBindVertexArray(VAO);
  while(!glfwWindowShouldClose(window)){ // main game loop 
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glfwSwapBuffers(window);
    glfwPollEvents();    
  }

  glfwTerminate();
}
*/