#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void LambdaHelloWorld(int n)
{
	std::cout << "Hello " << n << " World!" << std::endl;
}

void LambdaForEach(auto& data, void(*func)(int))
{
	for (int value : data)
		func(value);
}

void LambdaForEach(auto& data, const std::function<void(int)>& func)
{
	for (int value : data)
		func(value);
}

int Lambda()
{


	std::vector<int> data = { 1, 5, 3, 4, 8, 2, 1 };
	auto it = std::find_if(data.begin(), data.end(), [](int val) { return val > 3; });
	std::cout << *it << "\n";

	int a = 5;
	auto lambda = [&a](int value) {std::cout << "Value: " << value << " and " << a << "\n"; };
	a = 8;
	LambdaForEach(data, lambda);

	std::cin.get();
	return 0;
}