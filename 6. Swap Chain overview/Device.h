#pragma once

#include "Window.h"

namespace Core {
	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	struct QueueFamilyIndices {
		uint32_t graphicsFamily;
		uint32_t presentFamily;
		bool graphicsFamilyHasValue{ false };
		bool presentFamilyHasValue{ false };
		bool IsComplete(){ return graphicsFamilyHasValue && presentFamilyHasValue; }
	};

	class Device {
	private:
		// private member variables
		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;
		VkPhysicalDevice physicalDevice{ VK_NULL_HANDLE };
		VkCommandPool commandPool;

		VkDevice device;
		VkSurfaceKHR surface;
		VkQueue graphicsQueue;
		VkQueue presentQueue;

		Window& window;

		std::vector<const char*> validationLayers{ "VK_LAYER_KHRONOS_validation" };
		std::vector<const char*> deviceExtensions{ VK_KHR_SWAPCHAIN_EXTENSION_NAME };

		// private member functions
		void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
		VkCommandBuffer BeginSingleTimeCommands();
		void EndSingleTimeCommands(VkCommandBuffer commandBuffer);
		void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
		void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount);
		VkPhysicalDeviceProperties properties;

		void CreateInstance();
		void SetupDebugMessenger();
		void CreateSurface();
		void PickPhysicalDevice();
		void CreateLogicalDevice();
		void CreateCommandPool();

		bool IsDeviceSuitable(VkPhysicalDevice device);
		std::vector<const char*> GetRequiredExtensions();
		bool CheckValidationLayerSupport();
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
		void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		void HasGLFWRequiredInstanceExtensions();
		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);

	public:
		Device(Window& window);
		~Device();

		Device(const Device&) = delete;
		Device& operator=(const Device&) = delete;
		Device(Device&&) = delete;
		Device& operator=(Device&&) = delete;

		VkCommandPool GetCommandPool() const { return commandPool; }
		VkDevice GetDevice() const { return device; }
		VkSurfaceKHR GetSurface() const { return surface; }
		VkQueue GetGraphicsQueue() const { return graphicsQueue; }
		VkQueue GetPresentQueue() const { return presentQueue; }
		SwapChainSupportDetails GetSwapChainSupport() { return QuerySwapChainSupport(physicalDevice); }

		uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
		QueueFamilyIndices FindPhysicalQueueFamilies() { return FindQueueFamilies(physicalDevice); }
		VkFormat FindSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
		void CreateImageWithInfo(const VkImageCreateInfo& imageInfo, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);

#ifdef __DEBUG__MODE__
		static constexpr bool enableValidationLayers{ true };
#else
		static constexpr bool enableValidationLayers{ false };
#endif
	};
}


