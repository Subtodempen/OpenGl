cmake_minimum_required(VERSION 3.10)
project(MyOpenGLProject)

set(CMAKE_CXX_STANDARD 23)

# Add source files
set(SOURCES src/main.cpp src/CoreGl/GlWrapper.cpp src/Triangle/Triangle.cpp src/Shader/Shader.cpp src/ShaderProgram/ShaderProgram.cpp lib/glad.c)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Find and include GLFW
find_package(glfw3 3.3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})

# Create executable
add_executable(MyOpenGLProject ${SOURCES})
add_compile_options(-g)

# Link libraries
target_link_libraries(MyOpenGLProject glfw ${CMAKE_DL_LIBS})
