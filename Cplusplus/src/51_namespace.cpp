#include <iostream>
// NameSpace insine header.h
#include "lzm.h"

int fNameSpace()
{
	{
		lzm::Timer t;
		lzm::ScopedPtr<int> ptr = new int;
	}

	std::cin.get();
	return 0;
}