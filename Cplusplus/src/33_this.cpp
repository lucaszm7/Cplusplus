#include <iostream>
#include <string>

struct EntityThis
{
	float x, y, z;

	EntityThis(float x, float y, float z)
	{
		this->x = x;
		(*this).y = y;
		this->z = z;
	}

};

int f_this()
{
	EntityThis e(2, 3, 5);

	std::cin.get();
	return 0;
}