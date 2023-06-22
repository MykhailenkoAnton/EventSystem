#include <iostream>
//#include "glfw3.h"

#include "Window.h"


int main()
{
	Core::Window& window = Core::Window::getInstance();

	while (!glfwWindowShouldClose(window.getGLFWindow()))
	{
		glfwPollEvents();
		glfwSwapBuffers(window.getGLFWindow());
	}

	return 0;
}