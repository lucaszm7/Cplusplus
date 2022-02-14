#include <iostream>
#include <vector>

void FuncPtrHelloWorld(int n)
{
	std::cout << "Hello " << n << " World!" << std::endl;
}

void FuncPtrForEach(auto& data, void(*func)(int))
{
	for (int value : data)
		func(value);
}

int func_ptr()
{
	void(*FunctionPtrOld)(int) = FuncPtrHelloWorld;
	auto FunctionPtrAuto = FuncPtrHelloWorld;

	FunctionPtrOld(0);
	FunctionPtrAuto(1);

	typedef void(*FunctionPtr)(int);
	FunctionPtr function = FuncPtrHelloWorld;

	function(2);

	std::vector<int> data = { 1, 5, 3, 4, 8, 2, 1 };
	FuncPtrForEach(data, [](int value) {std::cout << value << "\n"; });

	std::cin.get();
	return 0;
}