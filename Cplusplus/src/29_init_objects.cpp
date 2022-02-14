#include <iostream>
#include <string>

using String = std::string;

class EntityInit
{
private:
	String m_Name;
public:
	EntityInit() : m_Name("Unknow") {}
	EntityInit(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

void PrintNameInit(const EntityInit& e)
{
	std::cout << e.GetName() << std::endl;
}

int init_objects()
{
	EntityInit e = EntityInit("Lucas");
	PrintNameInit(e);

	EntityInit* e0;

	{
		EntityInit* e1 = new EntityInit("Lucas");
		e0 = e1;
		PrintNameInit(*e0);
	}

	PrintNameInit(*e0);
	delete e0;
	std::cin.get();
	return 0;
}