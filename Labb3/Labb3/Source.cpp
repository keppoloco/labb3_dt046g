#include <iostream>
#include <iomanip>
#include <fstream>

#include "Datagenerator.h"
#include "Algorithms.h"
#include "Timer.h"
#include "Measurement.h"

#define COUNT 10
void print2DUtil(Node* root, int space);
void printHash(std::vector<HashNode*> hash);

const int DATA_SIZE = 200000;
const int REPETITIONS = 10;
const int SAMPLES = 50;

int main()
{
	std::vector<int> data;
	std::vector<double> period(SAMPLES);

	std::vector<HashNode*> hash_table;
	Node* tree = NULL;
	srand(time(NULL));
	// Prime number generator
	// 2 3 5 7 11 => N = 5
	//auto vec = GetPrimeVector(5);

	std::string filename[] = { "binary_search_tree.data", "binary_search.data", "hash_table.data", "sequential_search.data" };

	data = GetPrimeVector(DATA_SIZE * REPETITIONS);

	//hash_table = CreateHashTable(data.begin(), data.end());
	tree = CreateBinarySearchTree(data.begin(), data.end());

	std::ofstream os;
	os.open(filename[0], std::ios::out | std::ios::app);

	if (os.is_open())
	{
		os << "N\t" << "T[ms]\t" << "dev[ms]\t" << "Samples\n";
		for (int iter = 1; iter <= REPETITIONS; iter++)
		{
			for (int i = 0; i < SAMPLES; i++)
			{
				// number to find for each iteration
				int number_to_find = data[rand() % DATA_SIZE];
				// run it
				//period[i] = time_it(&sequential_search, data.begin(), data.begin() + (DATA_SIZE * iter), number_to_find);
				//period[i] = time_it(&binary_search, data.begin(), data.begin() + (DATA_SIZE * iter), number_to_find);
				period[i] = time_it(&binary_tree_search, tree, number_to_find * iter);
				//period[i] = time_it(&hash_table_search, hash_table.begin(), hash_table.end(), number_to_find);
			}
			os << DATA_SIZE * iter << "\t" << average_value(period) << "\t" << std_dev(period) << "\t" << SAMPLES << '\n';
		}
		os.close();
	}
	
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
	//printHash(hash_table);
	//print2DUtil(tree, 0);

	return 0;
}

void printHash(std::vector<HashNode*> table) {
	for (int i = 0; i < table.size(); i++) 
	{
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