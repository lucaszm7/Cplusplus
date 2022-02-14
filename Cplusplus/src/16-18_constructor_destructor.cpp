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

	void Print() override
	{
		std::cout << x << ", " << y << std::endl;
		std::cout << this->name << std::endl;
	}
};

static void PrintName(Entity* e)
{
	e->Print();
}
