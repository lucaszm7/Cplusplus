#include <iostream>

#include <utility>
#include <tuple>

std::tuple<std::string, std::string> function_tuple()
{
	std::string vs, fs;
	return std::make_pair(vs, fs);
}

struct MultipleReturn
{
	std::string vs, fs;

	MultipleReturn(std::string vs, std::string fs)
		: vs(vs), fs(fs) {}

};

void function_reference(std::string& vs, std::string& fs)
{
	// Do stuff
	vs = "Lucas";
	fs = "eh demais";
}

MultipleReturn function_struct()
{
	// Do stuff
	return MultipleReturn("Lucas", "eh demais");
}

int multiple_returns()
{
	std::tuple<std::string, std::string> source = function_tuple();

	std::string vs = std::get<0>(source);
	std::string fs = std::get<1>(source);

	std::cin.get();
	return 0;
}