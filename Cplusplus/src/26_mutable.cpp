#include <iostream>

class Entity
{
private:
	int m_X, m_Y;
	mutable int m_DebugCount;
public:
	int GetX() const
	{
		m_DebugCount++;
		return m_X;
	}
};

void PrintEntity(const Entity& e)
{
	std::cout << e.GetX() << std::endl;
}

int fMutable()
{

	Entity e;
	PrintEntity(e);
	int x = 8;
	auto f = [=]() mutable
	{
		x++;
		return pow(x, 2);
	};

	f();

	std::cin.get();
	return 0;
}