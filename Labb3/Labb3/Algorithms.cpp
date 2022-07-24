#include "Algorithms.h"

bool sequential_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& key)
{
    for (auto iter = first; first != last; iter++) {
        if (*iter == key) {
            return true;
        }
    }
    return false;
}

bool binary_search(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& key)
{
	std::cout << "avg: " << *first + distance(first, last) / 2 << '\n';
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

		else {
			last = mid - 1;
		}
	}
	return false;
}

bool binary_tree_search(Node* root, const int& key)
{
	Node* ptr = root;
	while (ptr != nullptr)
	{
		if (root->data == key)
		{
			return true;
		}
		else if (key < ptr->data)
		{
			ptr = ptr->left;
		}
		else 
		{
			ptr = ptr->right;
		}
	}
	return false;
}
