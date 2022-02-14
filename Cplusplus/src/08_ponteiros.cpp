#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int ponteiros()
{

	char* buffer = new char[8];
	memset(buffer, 1, 8);
	delete[] buffer;

	int* ptr;
	int* ptr2;
	int** ptr3;

	ptr = (int*)&ptr2;
	ptr3 = &ptr2;
	*ptr3 = ptr;

	*ptr2 = (int)&ptr;

	LOG(ptr);
	LOG(ptr2);
	LOG(ptr3);
	LOG(&ptr);
	LOG(&ptr2);
	LOG(&ptr3);

	std::cin.get();
	return 0;
}