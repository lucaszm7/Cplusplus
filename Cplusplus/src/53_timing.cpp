#include <iostream>
#include "lzm.h"
#include <thread>

bool is_prime(unsigned int n)
{
	for (unsigned int i = n - 1; i > 1; --i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int timing()
{
	using namespace std::literals::chrono_literals;

	auto start = std::chrono::high_resolution_clock::now();

	std::this_thread::sleep_for(1s);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duaration = end - start;

	std::cout << "Took: " << duaration.count() << "s\n";

	{
		lzm::Timer time;
		std::cout << "Is prime? " << is_prime(933199) << "\n";
	}

	std::cin.get();
	return 0;
}