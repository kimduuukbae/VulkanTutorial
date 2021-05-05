#pragma once

#include "Window.h"

namespace App {
	class FirstApp {
	private:
		static constexpr int width{ 800 };
		static constexpr int height{ 600 };

		Core::Window window{ width, height, "HELLO VULKAN!" };

	public:
		FirstApp() = default;
		~FirstApp() = default;

		void Run();
	};
}

