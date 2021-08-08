#include "stdafx.h"
#include "FirstApp.h"

namespace App {
	void FirstApp::Run() {
		while (!window.IsClosed()) {
			glfwPollEvents();
		}
	}
}