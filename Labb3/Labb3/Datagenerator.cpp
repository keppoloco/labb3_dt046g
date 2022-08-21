#include "Datagenerator.h"
#include <iostream>
struct Node* root = NULL;

// So I was using the theory of getting primes from the notes
// but i noticed an issue whenever getting primes
// if i sent n = 20000 i would only get approx. ~17 500 primes and not 20 000.
// this made my program faulty down the line when accessing indexes in the vector
std::vector<int> GetPrimeVector(const size_t n)
{
	size_t size = n;

	std::vector<int> primes;
	primes.push_back(2);

	int i = 3;
	while (primes.size() < size)
	{
		bool isPrime = true;
		for (int j = 0; j < size && std::pow(primes[j], 2) <= i; j++)
		{
			if (i % primes[j] == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			primes.push_back(i);
		}
		i++;
	}

	/*size_t size = n;
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
	}*/
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

	// similiar to quicksort, divide and conquer
	// partitions all the elements to either left of our value or right of our value depending if said value is lesser or larger
	auto lower = std::lower_bound(first, last, mid);
	auto higher = std::upper_bound(first, last, mid);

	// recursively build the tree and its nodes, lesser nodes to the left and larger nodes to the right of current node "mid"
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

std::vector<HashNode*> CreateHashTable(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	int size = std::distance(first, last);
	
	std::vector<HashNode*> table(size);

	for (auto iter = first; iter != last; iter++)
	{	
		// this is our hashing function
		int key = *iter % size;

		// if no nodes exists in current hash function 
		if (table.at(key) == nullptr)
		{
			table.at(key) = new HashNode(*iter);
		}
		// else we chain the nodes from left to right and enter our new hashnode that share the same hash as the previous
		else
		{
			HashNode* node = table.at(key);
			while (node->next != nullptr)
			{
				node = node->next;
			}
			node->next = new HashNode(*iter);
		}
	}

	return table;
}
