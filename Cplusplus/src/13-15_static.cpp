#include <iostream>

static void static_outside()
{
	static int s_Variable = 5;

	int variable = 55;
	// extern int variable;

}

struct Entity
{
	static int x, y;

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}

};

static void static_inside()
{
	Entity e;
	Entity::x = 10;
	Entity::y = 15;

	Entity e1;
	Entity::x = 20;
	Entity::y = 25;

	e.Print();
	e1.Print();

	std::cin.get();
}

static void Foo()
{
	static int i = 0;
	i++;
}

