#include <iostream>

#define log(x) std::cout << x << std::endl;

void incrementa(int& a)
{
	a = 20;
}

int references()
{
	int a = 5;
	int& ref = a;

	incrementa(ref);

	log(a);

	incrementa(a);

	log(ref);

	std::cin.get();
	return 0;
}