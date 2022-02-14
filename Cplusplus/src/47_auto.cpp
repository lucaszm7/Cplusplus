#include <iostream>
#include <vector>

class AutoString
{
private:
	const char* m_Name;
public:
	AutoString(const char* name)
		: m_Name(name) {}

	AutoString(const AutoString& ref)
		: m_Name(ref.m_Name)
	{
		std::cout << "Copying...\n";
	}

	friend inline std::ostream& operator << (std::ostream& out, AutoString& s);

};

inline std::ostream& operator << (std::ostream& out, AutoString& s)
{
	out << s.m_Name;
	return out;
}

auto auto_function()
{

	std::vector<AutoString> Strings;

	/*Strings.push_back("Lucas");
	Strings.push_back("Jose");
	Strings.push_back("Maria");*/

	Strings.reserve(3);
	Strings.emplace_back("Lucas");
	Strings.emplace_back("Jose");
	Strings.emplace_back("Maria");


	for (auto& string : Strings)
		std::cout << string << "\n";

	std::cin.get();
	return 0;
}