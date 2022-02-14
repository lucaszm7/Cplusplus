#include <iostream>
#include <string>

struct Entity34
{
	std::string name;

	Entity34(std::string name)
		: name(name)
	{
		std::cout << "Created Entity " << name << "!" << std::endl;
	}

	~Entity34()
	{
		std::cout << "Destroyed Entity " << name << "!" << std::endl;
	}
};

struct Entity34Teste
{
private:
	float* m_ptr;
public:
	Entity34Teste()
	{
		m_ptr = new float;
	}

	~Entity34Teste()
	{

	}

	float* GetPtrAddress()
	{
		return m_ptr;
	}

	void ShowPtrContent()
	{
		std::cout << *m_ptr << std::endl;
	}

};

class ScopedPtr
{
private:
	Entity34* m_Ptr;
public:
	ScopedPtr(Entity34* e)
		: m_Ptr(e)
	{}

	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int object_lifetime()
{
	{
		Entity34 e("e");
		ScopedPtr f = new Entity34("f");
	}

	float* f;

	{
		Entity34Teste e;
		f = e.GetPtrAddress();
		*f = 34;
		e.ShowPtrContent();
	}

	*f = 50;
	std::cout << *f << std::endl;

	std::cin.get();
	return 0;
}