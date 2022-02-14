#include <iostream>

class Vector3D
{
public:
	float x;
	float y;
	float z;

	float length()
	{
		return sqrtf(x * x + y * y + z * z);
	}

	void normalize()
	{
		float length = this->length();
		x = x / length;
		y = y / length;
		z = z / length;
	}

};

int classes()
{
	Vector3D position;
	position = { 4.3f, 7.4f, 8.424f };
	std::cout << position.length() << "\n";
	position.normalize();
	std::cout << position.length() << "\n";

	std::cout << position.x << " - " << position.y << " - " << position.z << " - " << std::endl;
	std::cin.get();

	return 0;
}