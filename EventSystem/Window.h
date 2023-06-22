#pragma once
#include <string>
#include "glfw3.h"
#include <functional>
#include "Event.h"

namespace Core
{
	class Window final
	{
	public:
	protected:
	private: 
		std::string name;
		int width, height;
		GLFWwindow* window = nullptr;
		std::function<void(Event&)> fnCallback;

		Window(const std::string& name, int width, int height);

		~Window();
	public:

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		
		static Window& getInstance() { static Window instance("Window", 1280, 720);
																	return instance; }

		void init(const std::string& name, int width, int height);

		__forceinline GLFWwindow* getGLFWindow() const { return window; }


		// callbacks
	public:
		void setFunctionCallback(const std::function<void(Event&)>& fn) { fnCallback = fn; }

		static void mouseMovedCallback(GLFWwindow* window, double x, double y);
		static void mouseScrollCallback(GLFWwindow* window, double x, double y);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void windowResizedCallback(GLFWwindow* window, int width, int height);
		static void windowClosedCallback(GLFWwindow* window);
	};

}