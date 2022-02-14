#include <iostream>
#include <string>
#include <vector>


struct vertex
{
public:
	float x, y, z;

	vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	vertex(const vertex& v)
		: x(v.x), y(v.y), z(v.z)
	{
		std::cout << "Copying..." << std::endl;
	}
};

std::ostream& operator << (std::ostream& out, vertex& v)
{
	out << v.x << ", " << v.y << ", " << v.z;
	return out;
}

int vec_advance()
{
	std::vector<vertex> vertices;
	vertices.reserve(3);
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);



	std::cin.get();
	return 0;
}