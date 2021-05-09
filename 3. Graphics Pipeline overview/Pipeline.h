#pragma once

#include <vector>
#include <string_view>

namespace Core {
	class Pipeline {
	private:
		static std::vector<char> ReadFile(const std::string_view& filePath);
		void CreateGraphicsPipeline(const std::string_view& vertFilePath, const std::string_view& fragFilePath);

	public:
		Pipeline(const std::string_view& vertFilePath, const std::string_view& fragFilePath);
	};
}
