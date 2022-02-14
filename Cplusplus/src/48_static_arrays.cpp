#include <iostream>
#include <array>

template <int size>
void PrintArray(const std::array<int, size>& data)
{
	for (int i = 0; i < data.size(); i++)
		std::cout << data[i] << "\n";
}

void ReversePrintArray(const auto& data)
{
	for (int i = data.size() - 1; i >= 0; i--)
		std::cout << data[i] << "\n";
}

int static_arrays()
{

	std::array<int, 3> data0 = { 1, 2, 3 };
	std::array<int, 7> data1 = { 1,2,3,4,5,6,7 };
	PrintArray<data0.size()>(data0);
	ReversePrintArray(data1);

	std::cin.get();
	return 0;
}