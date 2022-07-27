#include "Datagenerator.h"

std::vector<int> GetPrimeVector(const size_t n)
{
	size_t size = n;
	std::vector<bool> prime_index(size, true);
	prime_index[0] = false;
	prime_index[1] = false;

	int i = 2;
	while (i < size / 2) 
	{
		int divisor = i * 2;
		while (divisor < size) 
		{
			prime_index[divisor] = false;
			divisor += i;
		}
		i += 1;
		while (prime_index[i] != true) 
		{
			i += 1;
		}
	}

	std::vector<int> primes;
	int prime = 0;
	for (bool isPrime : prime_index)
	{
		if (isPrime)
		{
			primes.push_back(prime);
		}
		prime++;
	}
	return primes;
}

Node* CreateBinarySearchTree(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (first - last < 1) 
	{
		return nullptr;
	}

	auto mid = first + std::distance(first, last) / 2;
	Node* root = new Node(*mid);

	return root;
}

/*Node* InsertNode(Node* root, const int& data)
{
	if (!root) {
		return new InsertNode(root, data);
	}
	return nullptr;
}*/
