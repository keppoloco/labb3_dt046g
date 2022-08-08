#include "Datagenerator.h"

struct Node* root = NULL;

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
	if (std::distance(first,last) < 1) 
	{
		return root;
	}

	int mid = *(first + std::distance(first, last) / 2);

	if (root == NULL)
	{
		root = InsertNode(root, mid);
	}
	else
	{
		InsertNode(root, mid);
	}

	/*auto low = std::next(first);
	auto high = std::next(last, -1);

	root->left = CreateBinarySearchTree(low, last);
	root->right = CreateBinarySearchTree(first, high);
	*/
	// Partition lower numbers than mid and higher numbers than mid separately to get median value for each node below current.
	// t.ex. mid = 11
	// lower => 7, 11, 13
	//higher => 2, 3, 5
	auto lower = partition(first, last, [mid](int x) {return x  < mid; });
	auto higher = partition(first, last, [mid](int x) {return !(x > mid); });

	CreateBinarySearchTree(first, lower);
	CreateBinarySearchTree(higher, last);
	
	return root;
}

Node* InsertNode(Node* root, const int& data) 
{
	if (root == NULL)
	{
		return new Node(data);
	}

	if (data < root->data)
	{
		root->left = InsertNode(root->left, data);
	}
	
	else 
	{
		root->right = InsertNode(root->right, data);
	}

	return root;
}
