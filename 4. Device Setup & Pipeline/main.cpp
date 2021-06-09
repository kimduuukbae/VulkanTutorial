#include "stdafx.h"
#include "FirstApp.h"

#include <iostream>


int main() {
	App::FirstApp app{};

	try {
		app.Run();
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}