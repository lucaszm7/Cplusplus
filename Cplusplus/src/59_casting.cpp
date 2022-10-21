#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

class base_casting { int a; };

class deri_casting : public base_casting { int b; };

class anot_casting : public base_casting { int c; };

int casting()
{

	double a = 5.23;
	double b = (int)(a + 2.42);
	std::cout << b << "\n";

	b = static_cast<int>(a + 2.544);
	std::cout << b << "\n";

	// double* c = reinterpret_cast<base_casting*>(&a);

	deri_casting* derived = new deri_casting();

	base_casting* base = derived;

	// anot_casting* anot = dynamic_cast<anot_casting*>(base);

	std::cin.get();
	return 0;
}