#include <iostream>
// #include <GLFW/glfw3.h>

int static_dynamic_libraries()
{
	// Para incluir os header files
	// C++ - general - include directories - $(SolucionDir)dependencies\GLFW\include

	// Para incluir o código
	// Linker - general - include directories - $(SolucionDir)dependencies\GLFW\lib-vc2019
	// Linker - input - additional dependencies - glfw3.lib;

	// ===================================================================

	// E para trabalhar com DLL, precisamos agora linkar com glfw3dll.lib
	// e adicionar o arquivo .dll no mesmo local que o executável.

	// int a = glfwInit();
	// std::cout << a << std::endl;

	std::cin.get();
	return 0;
}