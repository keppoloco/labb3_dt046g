#pragma once
#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H
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

std::vector<int> GetPrimeVector(const size_t n);
Node* CreateBinarySearchTree(std::vector<int>::iterator first, std::vector<int>::iterator last);
Node* InsertNode(Node*, const int&);
#endif // !PRIMENUMBERGENERATOR_H

