#include <iostream>

class EntityConst
{
private:
	int* m_X, m_Y;
	mutable int Y;
public:
	const int* const GetX() const
	{
		Y = 3;
		return m_X;
	}
};

void PrintConstEntity(const EntityConst& e)
{
	std::cout << e.GetX() << std::endl;
}

int fConst()
{

	EntityConst e;
	PrintConstEntity(e);

	const int MAX_AGE = 90;

	const int* const a = new int(43);

	// *a = 2;

	// a = (int*)&MAX_AGE;

	std::cout << *a;

	std::cin.get();
	return 0;
}