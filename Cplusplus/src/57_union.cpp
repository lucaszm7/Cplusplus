#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

struct uniVec2
{
	float x, y;
};

struct uniVec4
{
	// Every data inside the union ocupy the same memory address
	// so, in reallity, they are just type punning (alias) of each other
	// different ways of representing the same thing
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			uniVec2 a, b;
		};
	};
};

int unions()
{
	uniVec4 ray = { 1.0f, 2.0f, 3.0f, 4.0f };
	ray.x = 5.0f;
	ray.a.y = 6.0f;



	std::cin.get();
	return 0;
}