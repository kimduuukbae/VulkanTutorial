#pragma once

#include "Window.h"
#include "Pipeline.h"
#include "Device.h"

namespace App {
	class FirstApp {
	private:
		static constexpr int width{ 800 };
		static constexpr int height{ 600 };

		Core::Window window{ width, height, "HELLO VULKAN!" };
		Core::Device device{ window };
		Core::Pipeline pipeline{device, 
			"shaders/simple_vs.vert.spv",
			"shaders/simple_fs.frag.spv",
		Core::Pipeline::DefaultPipelineConfigInfo(width, height)};

	public:
		FirstApp() = default;
		~FirstApp() = default;

		void Run();
	};
}

