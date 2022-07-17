#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

struct TypePunning
{
	int x, y;
};

int type_punning()
{
	int a = 50;
	double v = *(double*)&a;
	std::cout << v << std::endl;

	TypePunning e = { 5, 8 };
	int* pos = (int*)&e;
	std::cout << pos[0] << ", " << pos[1] << std::endl;

	std::cin.get();
	return 0;
}