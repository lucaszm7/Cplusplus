#include <iostream>

#define PI 3.1415936535

#if 1

#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif

#endif

int macros()
{

	LOG(PI);
	std::cin.get();
	return 0;
}