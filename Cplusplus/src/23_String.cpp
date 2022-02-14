#include <iostream>
#include <string>

int sString()
{
	// Has to be a const
	const char* name = "Lucas";
	// name[3] = 'd';

	std::cout << name << std::endl;

	char name2[6] = { 'L', 'u', 'c', 'a', 's', '\0' };

	std::cout << name2 << std::endl;

	// =================================================

	std::string sName = (char*)"Lukeda";
	sName[3] = 'r';

	sName += " Hello!";

	sName.size();

	std::cout << sName << std::endl;

	std::cin.get();
	return 0;
}