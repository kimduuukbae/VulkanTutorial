#include "stdafx.h"
#include "Pipeline.h"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace Core {
	std::vector<char> Pipeline::ReadFile(const std::string_view& filePath) {
		std::ifstream file{ filePath.data(), std::ios::ate | std::ios::binary };

		if (!file.is_open())
			throw std::runtime_error{ "failed to open file" };

		size_t fileSize{ static_cast<size_t>(file.tellg()) };
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		return buffer;
	}

	void Pipeline::CreateGraphicsPipeline(Device& device,
		const std::string_view& vertFilePath,
		const std::string_view& fragFilePath,
		const PipelineConfigInfo& configInfo) {
		auto vsCode{ ReadFile(vertFilePath) };
		auto fsCode{ ReadFile(fragFilePath) };

		std::cout << "Vertex Shader Code Size :" << vsCode.size() << std::endl;
		std::cout << "Fragment Shader Code Size:" << fsCode.size() << std::endl;
	}

	void Pipeline::CreateShaderModule(const std::vector<char*>& code, VkShaderModule* shaderModule){
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(device.GetDeivce(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
			throw std::runtime_error{ "failed to create shader module" };
	}

	Pipeline::Pipeline(Device& device,
		const std::string_view& vertFilePath,
		const std::string_view& fragFilePath,
		const PipelineConfigInfo& configInfo) : device{device} {

		CreateGraphicsPipeline(device, vertFilePath, fragFilePath, configInfo);
	}
	PipelineConfigInfo Pipeline::DefaultPipelineConfigInfo(uint32_t width, uint32_t height){
		PipelineConfigInfo configInfo{
			
		};

		return configInfo;
	}
}