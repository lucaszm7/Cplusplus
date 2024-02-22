#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

int GetRValue()
{
	return 10;
}

int& GetLValue()
{
	static int a = 10;
	return a;
}

void SetBothValue(int a)
{

}

void SetLValueReference(int& a)
{

}

void SetBothLValueReference(const int& a)
{

}

void PrintName(std::string& lvalueReferenceName)
{
	std::cout << "lvalueName: " << lvalueReferenceName << std::endl;
}

void PrintName(std::string&& rvalueReferenceName)
{
	std::cout << "rvalueName: " << rvalueReferenceName << std::endl;
}

int lvalues_and_rvalues()
{
	// lvalue and rvalue
	int a = 10;
	// we cannot do this: 10 = a;
	// cause 10 is a rvalue, and a is a lvalue
	// rvalue is a temporary value, which is created to be used in a single expression
	// lvalue is a value that has a name and can be referenced	
	// lvalue can be assigned to rvalue, but not vice versa

	// The function GetRValue() returns a rvalue too
	int b = GetRValue();

	// The function GetLValue() returns a lvalue reference
	GetLValue() = 20;

	// We can call Set value with both lvalue and rvalue
	SetBothValue(a);
	// As the rvalue here will be converted to a lvalue reference
	SetBothValue(10);

	SetLValueReference(a);

	SetBothLValueReference(a);
	SetBothLValueReference(10);

	// I cant have a lvalue reference from an rvalue
	// unless it is a const lvalue reference
	// int& c = 10; error
	const int& c = 10; // sucess

	std::string firstName = "Lucas";
	std::string lastName = "Morais";

	PrintName(firstName);
	PrintName(firstName + lastName);

	std::cin.get();
	return 0;
}