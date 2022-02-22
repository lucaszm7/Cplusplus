#include <iostream>
#include "lzm.h"
#include <thread>
#include <future>

unsigned int fibo(unsigned int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		std::cout << fibo(n - 1) + fibo(n - 2) << "\n";
	return fibo(n - 1) + fibo(n - 2);
}

int threads()
{
	using std::cout;
	std::thread worker(fibo, 5);

	cout << "Done\n";

	worker.join();

	std::cin.get();
	return 0;
}