#ifndef _LOG_H
#define _LOG_H

#include <iostream>
#include <chrono>

namespace lzm
{
	template <typename Dta>
	class ScopedPtr
	{
	private:
		Dta* ptr;
	public:
		ScopedPtr(Dta* alloc)
			:ptr(alloc) {}
		~ScopedPtr()
		{
			std::cout << "Deleting ptr...\n";
			delete ptr;
		}
	};

	struct Timer
	{
		std::chrono::steady_clock::time_point start;
		std::chrono::duration<double> duration;

		Timer()
		{
			start = std::chrono::high_resolution_clock::now();
		}

		~Timer()
		{
			duration = std::chrono::high_resolution_clock::now() - start;
			std::cout << "\nTook: " << duration.count() * 1000.0 << "ms\n";
		}

		double now()
		{
			duration = std::chrono::high_resolution_clock::now() - start;
			return duration.count() * 1000.0;
		}

	};
}

#endif