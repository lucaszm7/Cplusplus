#include <iostream>

int multiply(int a, int b)
{
	return a * b;
}

void log(int dta)
{
	std::cout << dta << "\n";
}

int functions()
{
	log(multiply(5, 8));
	std::cin.get();
	return 0;
}