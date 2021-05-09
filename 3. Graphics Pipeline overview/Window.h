#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <string_view>

namespace Core {
	class Window {
	private:
		GLFWwindow* window{ nullptr };
		const int width;
		const int height;

		std::string windowName;

		void InitWindow();

	public:
		Window(int sizeWidth, int sizeHeight, const std::string_view& windowName);
		~Window();

		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;

		bool IsClosed();
	};
}


