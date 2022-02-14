#include <iostream>

int loops()
{

	for (int i = 0; i < 5; ++i)
		std::cout << "Hello World" << std::endl;

	std::cin.get();
	return 0;
}