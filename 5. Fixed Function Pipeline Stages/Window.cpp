#include "stdafx.h"
#include "Window.h"
#include <stdexcept>

namespace Core {

	Window::Window(int sizeWidth, int sizeHeight, const std::string_view& windowName) :
		width{ sizeWidth },
		height{ sizeHeight },
		windowName{ windowName } {
		InitWindow();
	}

	Window::~Window(){
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	bool Window::IsClosed(){
		return glfwWindowShouldClose(window);
	}

	void Window::CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface){
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
			throw std::runtime_error{ "Failed to create window surface" };
	}

	void Window::InitWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}


