#include <iostream>

class Entity
{
private:
	float z;

protected:
	int x, y;
	void Print() {}

public:
	Entity()
	{
		x = 0.0;
		y = .0;
	}
};

class Player : public Entity
{
public:
	Player()
	{
		x = 2;
		Print();
	}
};

int visibility()
{
	Entity e;
	// Error
	// e.x = 2;
	std::cin.get();
	return 0;
}