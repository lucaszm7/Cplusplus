#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

class Mamifero
{
public:
	Mamifero() { std::cout << "Mamifero Constructed\n"; }
	~Mamifero() { std::cout << "Mamifero Destructed\n"; }
};

class Gato : public Mamifero
{
public:
	Gato() { std::cout << "Gato Constructed\n"; }
	~Gato() { std::cout << "Gato Destructed\n"; }
};

int main()
{
	
	Mamifero* mam = new Mamifero();
	delete mam;
	std::cout << "----------------\n";
	Gato* gat = new Gato();
	delete gat;
	std::cin.get();
	return 0;
}