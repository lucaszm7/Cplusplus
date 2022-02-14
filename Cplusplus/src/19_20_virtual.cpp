#include <iostream>

class Entity
{
public:
	float x, y;

	Entity()
	{
		x = 0.0f; y = 0.0f;
	}

	Entity(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	// Destructor
	~Entity()
	{
		std::cout << "Destructed!" << std::endl;
	}

	virtual void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	virtual void Move() = 0;

};


class Player : public Entity
{
public:
	const char* name;
	Player(float x, float y, const char* name = "") {
		this->x = x;
		this->y = y;
		this->name = name;
	}

	void Print()
	{
		std::cout << x << ", " << y << std::endl;
		std::cout << this->name << std::endl;
	}

	void Move() override
	{

	}

};

void PrintName(Entity* e)
{
	e->Print();
}

int fVirtual()
{
	Player* Lucas = new Player(1.23f, 4.56f, "Lucas");
	Entity* Raiza = new Player(5.67f, 8.90f);

	PrintName(Lucas);
	PrintName(Raiza);

	std::cin.get();

	return 0;
}