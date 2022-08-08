#include <iostream>
#include <iomanip>
#include "Datagenerator.h"
#include "Algorithms.h"

#define COUNT 10

void print2DUtil(Node* root, int space);
int main()
{
	struct Node* tree = NULL;
	// 2 3 5 7 11 13 => N = 15
	auto vec = GetPrimeVector(15);

	//for ()
	//auto lower = partition(first, last, [mid](int x) {return x < mid; });
	//auto higher = partition(first, last, [mid](int x) {return !(x > mid); });
	/*for (int prime : vec) 
	{
		std::cout << prime << '\n';
	}
	
	if (binary_search(vec.begin(), vec.end(), 3)) 
	{
		std::cout << "found element\n";
	}*/
	/*tree = InsertNode(tree, 2);
	tree = InsertNode(tree, 3);
	tree = InsertNode(tree, 5);
	tree = InsertNode(tree, 7);
	tree = InsertNode(tree, 11);
	display(tree);

	if (binary_tree_search(tree, 7))
	{
		std::cout << "Found element!!\n";
	}
	else
	{
		std::cout << "Did not find element\n";
	}*/

	tree = CreateBinarySearchTree(vec.begin(), vec.end());
	/*if (binary_tree_search(tree, 7))
	{
		std::cout << "Found element!!\n";
	}
	else
	{
		std::cout << "Did not find element\n";
	}*/
	print2DUtil(tree, 0);

	return 0;
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