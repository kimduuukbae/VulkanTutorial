#include "Pipeline.h"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace Core{
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

	void Pipeline::CreateGraphicsPipeline(const std::string_view& vertFilePath, const std::string_view& fragFilePath){
		auto vsCode{ ReadFile(vertFilePath) };
		auto fsCode{ ReadFile(fragFilePath) };

		std::cout << "Vertex Shader Code Size :" << vsCode.size() << std::endl;
		std::cout << "Fragment Shader Code Size:" << fsCode.size() << std::endl;
	}

	Pipeline::Pipeline(const std::string_view& vertFilePath, const std::string_view& fragFilePath){
		CreateGraphicsPipeline(vertFilePath, fragFilePath);
	}
}