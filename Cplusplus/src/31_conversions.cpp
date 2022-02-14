#include <iostream>
#include <string>

using String = std::string;

class EntityConversion
{
private:
	String m_Name;
	int m_Age;
public:

	EntityConversion(const std::string& name)
		: m_Name(name), m_Age(-1) {}

	explicit EntityConversion(int age)
		: m_Name("Unknow"), m_Age(age) {}

	const String& GetName() const { return m_Name; }
	const int GetAge() const { return m_Age; }

};

inline std::ostream& operator << (std::ostream& out, const EntityConversion& e)
{
	out << e.GetName() << ' ' << e.GetAge();
	return out;
}

void PrintNameConversion(const EntityConversion& e)
{
	std::cout << e << std::endl;
}

int conversion()
{
	EntityConversion a = std::string("Lucas");
	// EntityConversion b = 20;

	PrintNameConversion(std::string("Jose"));
	// PrintNameConversion(22);

	std::cin.get();
	return 0;
}