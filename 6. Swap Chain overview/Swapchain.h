#pragma once

#include "Device.h"

// vulkan headers
#include <vulkan/vulkan.h>

// std lib headers
#include <string>
#include <vector>

namespace Core {

class SwapChain {
 public:
  static constexpr int MAX_FRAMES_IN_FLIGHT = 2;

  SwapChain(Device &deviceRef, VkExtent2D windowExtent);
  ~SwapChain();

  SwapChain(const SwapChain &) = delete;
  void operator=(const SwapChain &) = delete;

  VkFramebuffer GetFrameBuffer(int index) { return swapChainFramebuffers[index]; }
  VkRenderPass GetRenderPass() { return renderPass; }
  VkImageView GetImageView(int index) { return swapChainImageViews[index]; }
  size_t GetImageCount() { return swapChainImages.size(); }
  VkFormat GetSwapChainImageFormat() { return swapChainImageFormat; }
  VkExtent2D GetSwapChainExtent() { return swapChainExtent; }
  uint32_t GetWidth() { return swapChainExtent.width; }
  uint32_t GetHeight() { return swapChainExtent.height; }

  float ExtentAspectRatio() {
    return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height);
  }
  VkFormat findDepthFormat();

  VkResult AcquireNextImage(uint32_t *imageIndex);
  VkResult SubmitCommandBuffers(const VkCommandBuffer *buffers, uint32_t *imageIndex);

 private:
  void CreateSwapChain();
  void CreateImageViews();
  void CreateDepthResources();
  void CreateRenderPass();
  void CreateFramebuffers();
  void CreateSyncObjects();

  // Helper functions
  VkSurfaceFormatKHR ChooseSwapSurfaceFormat(
      const std::vector<VkSurfaceFormatKHR> &availableFormats);
  VkPresentModeKHR ChooseSwapPresentMode(
      const std::vector<VkPresentModeKHR> &availablePresentModes);
  VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;

  std::vector<VkFramebuffer> swapChainFramebuffers;
  VkRenderPass renderPass;

  std::vector<VkImage> depthImages;
  std::vector<VkDeviceMemory> depthImageMemorys;
  std::vector<VkImageView> depthImageViews;
  std::vector<VkImage> swapChainImages;
  std::vector<VkImageView> swapChainImageViews;

  Device &device;
  VkExtent2D windowExtent;

  VkSwapchainKHR swapChain;

  std::vector<VkSemaphore> imageAvailableSemaphores;
  std::vector<VkSemaphore> renderFinishedSemaphores;
  std::vector<VkFence> inFlightFences;
  std::vector<VkFence> imagesInFlight;
  size_t currentFrame = 0;
};

}  // namespace lve
