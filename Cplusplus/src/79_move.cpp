#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

class MyStr
{
public:
	MyStr()
	{
		std::cout << "Create Default MyStr" << std::endl;
		m_Size = 0;
		m_Data = nullptr;
	}
	MyStr(const char* str)
	{
		std::cout << "Create MyStr" << std::endl;
		m_Size = strlen(str);
		m_Data = new char[m_Size];
		memcpy(m_Data, str, m_Size);
	}

	MyStr(const MyStr& other)
	{
		std::cout << "Copy MyStr" << std::endl;
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	MyStr(MyStr&& other) noexcept
	{
		std::cout << "Move MyStr" << std::endl;
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	MyStr& operator=(const MyStr& other)
	{
		std::cout << "Copy Assign MyStr" << std::endl;

		if (this == &other)
			return *this;

		delete[] m_Data;
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);

		return *this;
	}

	MyStr& operator=(MyStr&& other) noexcept
	{
		std::cout << "Move Assign MyStr" << std::endl;

		if (this == &other)
			return *this;

		delete[] m_Data;
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;

		return *this;
	}

	void Print()
	{
		for (size_t i = 0; i < m_Size; i++)
			std::cout << m_Data[i];
		std::cout << std::endl;
	}

	~MyStr()
	{
		std::cout << "Destroy MyStr" << std::endl;
		delete[] m_Data;
	}

private:
	char* m_Data;
	size_t m_Size;
};

class MyEntity
{
public:
	MyEntity(const MyStr& name)
		: m_Name(name)
	{
	}

	MyEntity(MyStr&& name)
		: m_Name(std::move(name)) // std::move(name)
	{
	}

	void PrintName()
	{
		m_Name.Print();
	}

private:
	MyStr m_Name;
};

MyStr CreateString()
{
	MyStr str("Goodbye");
	return str;
}

int move_79()
{
	MyEntity e("Name");
	e.PrintName();

	MyStr str("Hello");

	str.Print();

	MyStr str2 = std::move(str);

	str.Print();
	str2.Print();

	MyStr str3;
	str3 = std::move(str2);

	str.Print();
	str2.Print();
	str3.Print();

	MyStr str4;
	str4 = CreateString();
	str4.Print();

	std::cin.get();
	return 0;
}