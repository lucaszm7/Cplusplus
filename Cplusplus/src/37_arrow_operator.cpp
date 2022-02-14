#include <iostream>
#include <string>
#include <memory>

class Arrow
{
public:
	int x;

	void Print() const
	{
		std::cout << "Hellow" << std::endl;
	}
};

class ArrowPtr
{
private:
	Arrow* m_Obj;
public:
	ArrowPtr(Arrow* ptr)
		: m_Obj(ptr) {}

	const Arrow* operator -> () const
	{
		return m_Obj;
	}

};

int arrow_operator()
{
	const ArrowPtr ptr = new Arrow;
	ptr->Print();

	std::cin.get();
	return 0;
}