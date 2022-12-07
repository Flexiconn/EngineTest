#pragma once
#include <vector>
#include "GameObject.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class Render
{



public:
	//struct XYZ {
	//	float X, Y, Z;
	//};

	//struct Object {
	//	struct XYZ scale;
	//	struct XYZ position;
	//	struct XYZ rotation;
	//};
	void SetUp(GLFWwindow* newWindow);
	void RenderFrame(std::vector<GameObject*> objects);
	void Clean();
	Render();
	~Render();

private:

};

