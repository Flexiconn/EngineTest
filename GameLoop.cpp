#include "GameLoop.h"
#include <iostream>
#include "Render.h"
#include "TestObject.h"
#include <GLFW/glfw3.h>
#include "KeyLogging.h"

int GameLoop::Loop(Scene scene) {
	Render render; 
    GLFWwindow* window;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    // --------------------
    window = glfwCreateWindow(800, 600, "2T3 Engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

	KeyLogging* p1 = KeyLogging::getInstance();
	p1->setWindow(window);

	render.SetUp(window);
	while (true) {
		
		//execute logic
		for (auto& object : scene.GetGameObjects()) {
			object->Update();
		}
		//render objects
		render.RenderFrame(scene.GetGameObjects());
		
		//execute logic
		
	}
	render.Clean();
}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}