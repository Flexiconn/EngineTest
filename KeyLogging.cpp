#include "KeyLogging.h"

bool KeyLogging::IsKeyPressed(int keyCode) {
	if (glfwGetKey(window, keyCode) == GLFW_PRESS) {
		return true;
	}
	return false;
}

KeyLogging::KeyLogging()
{
}

KeyLogging::~KeyLogging()
{
}

void KeyLogging::setWindow(GLFWwindow* newWindow) {
	window = newWindow;
}

KeyLogging* KeyLogging::inst_ = NULL;

KeyLogging* KeyLogging::getInstance() {
	if (inst_ == NULL) {
		inst_ = new KeyLogging();
	}
	return(inst_);
}