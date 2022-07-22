#include <iostream>
#include "Primenumbergenerator.h"
#include "Algorithms.h"

int main()
{
	auto vec = getPrimeVector(30);
	if (sequential_search(vec.begin(), vec.end(), 23)) {
		std::cout << "found 23!" << '\n';
	}

	return 0;
}