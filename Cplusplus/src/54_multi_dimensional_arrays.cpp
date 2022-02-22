#include <iostream>
#include "lzm.h"
#include <thread>


int multi_dimensional_array()
{
	// We are allocating 50 integers = 200 bytes
	int* a1d = new int[50];

	// We are allocating 50 integer pointer = 200 bytes
	int** a2d = new int* [50];

	// Now we are going to each allocated integer pointer, and then assigning
	// them to a 1D array
	for (int i = 0; i < 50; ++i)
		a2d[i] = new int[50];

	a2d[0][0] = 20;
	printf("%d\n", a2d[0][0]);

	// And now we repeat that ofr other dimensions...
	int*** a3d = new int** [10];

	for (int i = 0; i < 10; ++i)
	{
		a3d[i] = new int* [10];
		for (int j = 0; j < 10; ++j)
		{
			a3d[i][j] = new int[10];
		}
	}

	a3d[0][0][0] = 30;
	printf("%d\n", a3d[0][0][0]);


	// For deleting then now

	// 1D
	delete[] a1d;

	// 2D
	for (int i = 0; i < 50; ++i)
		delete[] a2d[i];
	delete[] a2d;

	// 3D
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			delete[] a3d[i][j];
		}
		delete[] a3d[i];
	}
	delete[] a3d;





	std::cin.get();
	return 0;
}