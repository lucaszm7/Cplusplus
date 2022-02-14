#include <iostream>

static int s_Level = 1;
static int s_Speed = 2;

int ternary_operator()
{
	// Isso
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;

	// Igual a isso
	//		  Condition ? True : False
	s_Speed = s_Level > 5 ? 10 : 5;

	std::string rank = s_Level > 30 ? "Master" : "Beginner";

	std::cin.get();
	return 0;
}