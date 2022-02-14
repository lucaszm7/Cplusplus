#include <iostream>
#include <string>
#include <vector>

#define vertex vertex_vec_begin

class vertex
{
public:
	float x, y, z;
};

std::ostream& operator << (std::ostream& out, vertex& v)
{
	out << v.x << ", " << v.y << ", " << v.z;
	return out;
}

int vec_begin()
{
	std::vector<vertex> vertices;

	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 3, 6, 5 });

	for (int i = 0; i < vertices.size(); ++i)
		std::cout << vertices[i] << std::endl;

	vertices.erase(vertices.begin() + 1);

	for (vertex& v : vertices)
		std::cout << v << std::endl;

	vertices.clear();

	std::cin.get();
	return 0;
}