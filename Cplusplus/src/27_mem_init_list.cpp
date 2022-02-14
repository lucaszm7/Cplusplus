#include <iostream>

class EntityList
{
private:
	std::string m_Name;
	int m_Score;
public:

	EntityList()
		: m_Name("Unknow"), m_Score(0)
	{
	}

	EntityList(const std::string& name)
		: m_Name(name), m_Score(0)
	{
	}

	const std::string GetName() const { return m_Name; }
};

void PrintName(const EntityList& e)
{
	std::cout << e.GetName() << std::endl;
}

int mem_init_list()
{

	EntityList e0;
	PrintName(e0);

	EntityList e1("Lucas");
	PrintName(e1);



	std::cin.get();
	return 0;
}