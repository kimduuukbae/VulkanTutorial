#pragma once

#include "Window.h"
#include "Pipeline.h"

namespace App {
	class FirstApp {
	private:
		static constexpr int width{ 800 };
		static constexpr int height{ 600 };

		Core::Window window{ width, height, "HELLO VULKAN!" };
		Core::Pipeline pipeline{"shaders/simple_vs.vert.spv", "shaders/simple_fs.frag.spv"};

	public:
		FirstApp() = default;
		~FirstApp() = default;

		void Run();
	};
}

