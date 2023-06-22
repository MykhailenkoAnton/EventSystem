#include <iostream>
#include "Window.h"
#include "MouseEvent.h"
#include "KeyboardEvent.h"
#include "WindowEvent.h"

namespace Core
{
	Window::Window(const std::string& name, int width, int height)
	{
		init(name, width, height);
		setFunctionCallback([this](Event& e)
			{
				if (e.getType() == Event::EventType::WINDOWS_CLOSED_EVENT)
				{
					glfwSetWindowShouldClose(window, GL_TRUE);
				}
				std::cout << e.format() << std::endl;
			});
	}

	Window::~Window()
	{
		glfwWindowShouldClose(window);
	}

	void Window::init(const std::string& name, int width, int height)
	{
		this->name = name;
		this->width = width;
		this->height = height;


		if (!glfwInit())
		{
			return;
		}

		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

		if (!window)
		{
			return;
		}

		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, this);
		glfwSetCursorPosCallback(window, mouseMovedCallback);
		glfwSetScrollCallback(window, mouseScrollCallback);
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetKeyCallback(window, keyCallback);
		glfwSetWindowSizeCallback(window, windowResizedCallback);
		glfwSetWindowCloseCallback(window, windowClosedCallback);

	}

	void Window::mouseMovedCallback(GLFWwindow* window, double x, double y)
	{
		auto &handle  = *(Window*)glfwGetWindowUserPointer(window);
		MouseMovedEvent m(x, y);
		handle.fnCallback(m);
	}

	void Window::mouseScrollCallback(GLFWwindow* window, double x, double y)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		MouseScrollEvent m(y);
		handle.fnCallback(m);
	}

	void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			MouseButtonPressed m(button);
			handle.fnCallback(m);
		}
		else
		{
			MouseButtonReleased m(button);
			handle.fnCallback(m);
		}
	}
	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			KeyPressedEvent m(key);
			handle.fnCallback(m);
		}
		else if(action == GLFW_REPEAT)
		{
			KeyReleasedEvent m(key);
			handle.fnCallback(m);
		}
		else if (action == GLFW_REPEAT)
		{
			KeyRepeatEvent m(key);
			handle.fnCallback(m);
		}
	}

	void Window::windowResizedCallback(GLFWwindow* window, int width, int height)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		WindowResizedEvent w(width, height);
		handle.width = width;
		handle.height = height;
		handle.fnCallback(w);
	}

	void Window::windowClosedCallback(GLFWwindow* window)
	{
		auto& handle = *(Window*)glfwGetWindowUserPointer(window);
		WindowCloseEvent c;
		handle.fnCallback(c);
	}
}