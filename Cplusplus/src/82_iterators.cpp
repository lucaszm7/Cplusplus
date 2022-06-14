#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>


int iterators()
{
	std::vector<int> values = { 1, 2, 3, 4, 5 };

	for (int value : values)
	{
		std::cout << value << std::endl;
	}

	for (std::vector<int>::iterator it = values.begin(); it != values.end(); ++it)
	{
		std::cout << *it << std::endl;
	}



	std::cin.get();
	return 0;
}