#pragma once
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Node.h"
#include <vector>
#include <iostream>

bool sequential_search(std::vector<int>::iterator, std::vector<int>::iterator, const int&);
bool binary_search(std::vector<int>::iterator, std::vector<int>::iterator, const int&);
bool binary_tree_search(Node*, const int&);
bool hash_table_search(std::vector<HashNode*>::iterator, std::vector<HashNode*>::iterator, const int&);

#endif // !ALGORITHMS_H

