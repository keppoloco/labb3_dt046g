#pragma once
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>

struct Node {
	Node(int data) : data(data), left(nullptr), right(nullptr) {}
	int data;
	Node* left;
	Node* right;
};

struct HashNode {
	HashNode(int data) :data(data), next(nullptr) {};
	int data;
	HashNode* next;
};

bool sequential_search(std::vector<int>::iterator, std::vector<int>::iterator, const int&);
bool binary_search(std::vector<int>::iterator, std::vector<int>::iterator, const int&);

#endif // !ALGORITHMS_H

