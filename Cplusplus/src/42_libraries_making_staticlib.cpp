#include <iostream>
#include "Engine.h"

int making_libraries()
{
	// Project - Add - Reference
	Engine::StartEngine();

	Engine::vec3 origin(2, 3, 4);

	std::cin.get();
	return 0;
}