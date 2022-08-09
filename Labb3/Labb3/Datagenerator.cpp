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

	// t.ex. mid = 11
	// lower => 13
	// higher => 2, 3, 5, 7
	auto lower = std::partition(first, last, [mid](int x) {return x  < mid; });
	auto higher = std::partition(first, last, [mid](int x) {return !(x > mid); });

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
		int key = *iter % size;
		if (table.at(key) == nullptr)
		{
			table.at(key) = new HashNode(*iter);
		}
		else
		{
			HashNode* node = table.at(key);
			while (node->next != nullptr)
			{
				node = node->next;
			}
			//table.at(key)->next = new HashNode(*iter);
			node->next = new HashNode(*iter);
		}
	}

	return table;
}
