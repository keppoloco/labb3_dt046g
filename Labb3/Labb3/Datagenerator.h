#pragma once
#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H
#include "Node.h"
#include <vector>
#include <algorithm>

std::vector<int> GetPrimeVector(const size_t n);
Node* CreateBinarySearchTree(std::vector<int>::iterator first, std::vector<int>::iterator last);
Node* InsertNode(Node*, const int&);
#endif // !PRIMENUMBERGENERATOR_H

