#include <iostream>
#include "Datagenerator.h"
#include "Algorithms.h"

int main()
{
	// 2 3 5 7 => N = 10
	auto vec = GetPrimeVector(10);

	for (int prime : vec) 
	{
		std::cout << prime << '\n';
	}
	
	if (binary_search(vec.begin(), vec.end(), 3)) 
	{
		std::cout << "found element\n";
	}

	return 0;
}