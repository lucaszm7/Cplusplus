#include <iostream>
#include <string>
#include <memory>

class String
{

private:
	char* m_Buffer;
	unsigned int m_Size;

public:

	String(const char* str)
	{
		m_Size = strlen(str);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, str, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other)
		: m_Size(other.m_Size)
	{
		std::cout << "Copying String " << other.m_Buffer << "..." << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}

	friend std::ostream& operator << (std::ostream& out, const String& str);

	char& operator [] (unsigned int index)
	{
		return m_Buffer[index];
	}
};

std::ostream& operator << (std::ostream& out, const String& str)
{
	out << str.m_Buffer;
	return out;
}

void Print(const String& str)
{
	std::cout << str << std::endl;
}

int copying()
{
	String name = "Lucas";
	String name0 = name;

	name0[2] = 'k';

	Print(name);
	Print(name0);

	std::cin.get();
	return 0;
}