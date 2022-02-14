#include <iostream>

int stack_vs_heap()
{

	int a = 5;
	int b[5] = { 1, 2, 3, 4, 5 };

	int* ha = new int;
	*ha = 5;

	int* hb = new int[5];
	hb[0] = 1;
	hb[1] = 2;
	hb[2] = 3;
	hb[3] = 4;
	hb[4] = 5;


	std::cin.get();
	return 0;
}