#include <iostream>

int conditions()
{
	int a = 255;
	char b = 255;

	if (b == (char)a)
	{
		std::cout << "Its equal" << std::endl;
	}

	int x = 50;

	x == 0 ? std::cout << "ITS 0" << "\n" : std::cout << "ITS NOT 0" << "\n";

	if (x == 10)
		std::cout << "ITS 10" << "\n";
	else
		if (x == 20)
			std::cout << "ITS 20" << "\n";
		else
			if (x == 50)
				std::cout << "ITS 50" << "\n";


	std::cout << "Hello World" << std::endl;
	std::cin.get();

	return 0;
}