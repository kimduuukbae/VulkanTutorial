#pragma once

#include "Device.h"

namespace Core {

	struct PipelineConfigInfo {
		/*
			파이프 라인 구성 방법을 지정하는 데이터가 포함될 것.
			여러 파이프라인간에 구성을 공유할 수 있어 유연성을 챙김
		*/

		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout{ nullptr };
		VkRenderPass renderPass{ nullptr };
		uint32_t subPass{ 0 };

		VkViewport viewport;
		VkRect2D scissor;
	};

	class Pipeline {
	private:
		Device& device;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

		static std::vector<char> ReadFile(const std::string_view& filePath);
		void CreateGraphicsPipeline(Device& device,
			const std::string_view& vertFilePath, 
			const std::string_view& fragFilePath,
			const PipelineConfigInfo& configInfo);

		void CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

	public:
		Pipeline(Device& device,
			const std::string_view& vertFilePath,
			const std::string_view& fragFilePath,
			const PipelineConfigInfo& configInfo);

		~Pipeline();

		Pipeline(const Pipeline&) = delete;
		Pipeline(Pipeline&&) = delete;

		static PipelineConfigInfo DefaultPipelineConfigInfo(uint32_t width, uint32_t height);
	};
}
