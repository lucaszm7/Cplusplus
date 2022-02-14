#include <iostream>
#include <string>

using String = std::string;

class EntityNew
{
private:
	String m_Name;
public:
	EntityNew() : m_Name("Unknow") {}
	EntityNew(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

void PrintNameNew(const EntityNew& e)
{
	std::cout << e.GetName() << std::endl;
}

int new_keyword()
{

	int a = 5;

	int* b = new int[50]; // 200 Bytes
	delete[] b;

	EntityNew* e0 = new EntityNew[50];
	EntityNew* e1 = new EntityNew();
	EntityNew* e2 = (EntityNew*)malloc(sizeof(EntityNew));

	std::cout << sizeof(*e0) << "\n";

	delete[] e0;
	delete e1;
	free(e2);

	std::cin.get();
	return 0;
}