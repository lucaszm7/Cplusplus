#include <iostream>
#include <array>

int fArray()
{
	int example[5] = { 1, 2, 3, 4, 5 };

	std::cout << example << "\n";

	int* ptr = example;

	*(ptr + 2) = 8;

	std::array<int, 5> anotherArray;

	std::cin.get();
	return 0;
}