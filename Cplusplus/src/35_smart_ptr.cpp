#include <iostream>
#include <string>
#include <memory>

struct EntityPtr
{
	const char* name;
	EntityPtr(const char* name)
		: name(name)
	{
		std::cout << "Entity " << name << " Created!\n";
	}

	~EntityPtr()
	{
		std::cout << "Entity " << name << " Destroyed!\n";
	}
};

int smart_ptr()
{

	{
		std::weak_ptr<EntityPtr> s0;
		{
			std::unique_ptr<EntityPtr> e = std::make_unique<EntityPtr>("e");

			std::shared_ptr<EntityPtr> s = std::make_shared<EntityPtr>("s");
			s0 = s;
		}
	}

	

	std::cin.get();
	return 0;
}