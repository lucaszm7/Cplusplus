#include <iostream>
#include <string>

struct vec2
{
	float x, y;

	vec2(float x, float y)
		: x(x), y(y) {}

	vec2 operator + (const vec2& other) const
	{
		return vec2(x + other.x, y + other.y);
	}
};

std::ostream& operator << (std::ostream& out, vec2& vec)
{
	out << vec.x << ", " << vec.y;
	return out;
}

int operators()
{
	vec2 origin(4, 5);
	vec2 dir(2, 3);

	vec2 endPoint = origin + dir;

	std::cout << endPoint << std::endl;

	std::cin.get();
	return 0;
}