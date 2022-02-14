#include "Engine.h"

#include <iostream>

namespace Engine
{
	void StartEngine()
	{
		std::cout << "Engine Started..." << std::endl;
	}

	vec3::vec3(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

}