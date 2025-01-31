#include "Algorithms.h"
#include "Datagenerator.h"

bool sequential_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& key)
{
    for (auto iter = first; first != last; iter++) 
	{
        if (*iter == key) 
		{
            return true;
        }
    }
    return false;
}

bool binary_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& key)
{
	while (first <= last) 
	{
		auto mid = first + std::distance(first, last) / 2;

		if (*mid == key)
		{
			return true;
		}

		if (*mid < key) 
		{
			first = mid + 1;
		}

		else 
		{
			last = mid - 1;
		}
	}
	return false;
}

bool binary_tree_search(Node* root, const int& key)
{
	while (root != nullptr)
	{
		if (root->data == key)
		{
			return true;
		}
		else if (key < root->data)
		{
			root = root->left;
		}
		else 
		{
			root = root->right;
		}
	}
	return false;
}

bool hash_table_search(std::vector<HashNode*>::iterator first, std::vector<HashNode*>::iterator last, const int& key)
{
	HashNode* node_index = *(first + (key % std::distance(first, last)));
	
	while (node_index != nullptr)
	{
		if (node_index->data == key)
		{
			return true;
		}
		node_index = node_index->next;
	}

	return false;
}
