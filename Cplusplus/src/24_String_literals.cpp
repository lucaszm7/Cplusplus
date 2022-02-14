#include <iostream>

int string_literals()
{

	using namespace std::string_literals;

	std::wstring sname = L"Lucas"s + L" Morais";

	const char* ex = R"(Line1
		Line2
		Line3)";

	// 8 - bits
	// UTF-8
	const char* name0 = "Lucas";

	// 16(windows) ou 32(linux) - bits
	const wchar_t* wname = L"Lucas";

	// UTF-16
	// 16 - bits
	const char16_t* name1 = u"Lucas";

	// UTF-32
	// 32 - bits
	const char32_t* name2 = U"Lucas";

	std::cin.get();
	return 0;
}