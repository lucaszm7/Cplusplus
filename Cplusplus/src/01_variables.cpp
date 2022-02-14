#include <iostream>

int variables()
{
	std::cout << "INT: " << sizeof(int) << std::endl;
	std::cout << "CHAR: " << sizeof(char) << std::endl;
	std::cout << "FLOAT: " << sizeof(float) << std::endl;
	std::cout << "DOUBLE: " << sizeof(double) << std::endl;
	std::cout << "LONG: " << sizeof(long int) << std::endl;
	std::cout << "UNSIGNED: " << sizeof(unsigned int) << std::endl;

	char a = 65;
	int b = 65;

	std::cout << a << std::endl;
	std::cout << (char)b << std::endl;

	// ================================================================

	int d = 2000000001;
	float e = (float)d;
	e += 0.5;
	int f = (int)e;
	std::cout << "INT: " << d << "\n" << "FLOAT: " << e << "\n" << "INT: " << f << "\n";

	std::cin.get();
	return 0;
}