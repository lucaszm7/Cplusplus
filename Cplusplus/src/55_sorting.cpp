#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>


int sorting()
{

	std::vector<int> values = { 5, 6, 2, 7, 1, 8 };
	std::sort(values.begin(), values.end(), [](int a, int b)
		{
			// Return true if first element (a) comes before second element (b)
			return (a < b);
		});

	for (int v : values)
		std::cout << v << std::endl;

	std::cin.get();
	return 0;
}