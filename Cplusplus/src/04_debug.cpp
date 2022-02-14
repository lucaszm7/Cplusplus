#include <iostream>

int debug()
{

	int a = 65;
	++a;

	const char* string = "Hello";

	for (int i = 0; i < 5; ++i)
	{
		const char c = string[i];
		std::cout << c << std::endl;
	}

	for (int j = 0; j < 5; j++)
	{
		const char c = string[j];
		std::cout << c << std::endl;
	}

	std::cout << "Hello World" << std::endl;
	std::cin.get();

	return 0;
}