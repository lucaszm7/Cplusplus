#include <iostream>

int control_flow()
{

	for (int i = 0; i < 10; ++i)
	{
		if (i == 3)
			continue;
		else if (i == 5)
			break;
		std::cout << "Hello World" << std::endl;
	}

	std::cin.get();
	return 0;
}