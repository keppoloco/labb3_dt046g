#include <iostream>
#include <iomanip>
#include "Datagenerator.h"
#include "Algorithms.h"

#define COUNT 10
void print2DUtil(Node* root, int space);
void printHash(std::vector<HashNode*> hash);

int main()
{

	// Prime number generator
	// 2 3 5 7 11 13 => N = 15
	auto vec = GetPrimeVector(15);

	// Hash table
	
	std::vector<HashNode*> hash_table = CreateHashTable(vec.begin(), vec.end());
	if (hash_table_search(hash_table.begin(), hash_table.end(), 23))
	{
		std::cout << "Found data!!" << '\n';
	}
	else
	{
		std::cout << "Not found.\n";
	}

	// binary search
	/*struct Node* tree = NULL;
	tree = CreateBinarySearchTree(vec.begin(), vec.end());
	
	if (binary_search(vec.begin(), vec.end(), 3)) 
	{
		std::cout << "found element\n";
	}*/

	// Binary tree
	/*tree = CreateBinarySearchTree(vec.begin(), vec.end());
	if (binary_tree_search(tree, 7))
	{
		std::cout << "Found element!!\n";
	}
	else
	{
		std::cout << "Did not find element\n";
	}*/

	// Print functions
	printHash(hash_table);
	/*print2DUtil(tree, 0);*/

	return 0;
}

void printHash(std::vector<HashNode*> table) {
	for (int i = 0; i < table.size(); i++) {
		std::cout << std::endl;
		std::cout << i << " --> ";
		if (table.at(i) == nullptr)
		{
			continue;
		}
		else
		{
			std::cout << table.at(i)->data << " ";
			if (table.at(i)->next != nullptr)
				std::cout << table.at(i)->next->data;
		}
		std::cout << std::endl;
	}
}

void print2DUtil(Node* root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";

	// Process left child
	print2DUtil(root->left, space);
}