#include "stdafx.h"
#include "FirstApp.h"

#include <stdexcept>

namespace App {
	FirstApp::FirstApp() {
		CreatePipelineLayout();
		CreatePipeline();
		CreateCommandBuffers();
	}

	FirstApp::~FirstApp() {
		vkDestroyPipelineLayout(device.GetDevice(), pipelineLayout, nullptr);
	}

	void FirstApp::CreatePipelineLayout(){
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		if (vkCreatePipelineLayout(device.GetDevice(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error{ "failed to create graphics pipeline" };
		}
	}

	void FirstApp::CreatePipeline(){
		auto pipelineConfig{ Core::Pipeline::DefaultPipelineConfigInfo(swapChain.GetWidth(), swapChain.GetHeight()) };
		pipelineConfig.renderPass = swapChain.GetRenderPass();
		pipelineConfig.pipelineLayout = pipelineLayout;
		pipeline = std::make_unique<Core::Pipeline>(device,
			"shaders/simple_vs.vert.spv",
			"shaders/simple_fs.frag.spv",
			pipelineConfig);
	}

	void FirstApp::CreateCommandBuffers()
	{
	}

	void FirstApp::DrawFrame()
	{
	}

	void FirstApp::Run() {
		while (!window.IsClosed()) {
			glfwPollEvents();
		}
	}
}