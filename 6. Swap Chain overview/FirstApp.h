#pragma once

#include "Window.h"
#include "Pipeline.h"
#include "Device.h"
#include "Swapchain.h"

namespace App {
	class FirstApp {
	private:
		static constexpr int width{ 800 };
		static constexpr int height{ 600 };

		void CreatePipelineLayout();
		void CreatePipeline();
		void CreateCommandBuffers();
		void DrawFrame();

		Core::Window window{ width, height, "HELLO VULKAN!" };
		Core::Device device{ window };
		Core::SwapChain swapChain{ device, window.GetExtent() };
		std::unique_ptr<Core::Pipeline> pipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete;

	public:
		FirstApp();
		~FirstApp();

		void Run();
	};
}

