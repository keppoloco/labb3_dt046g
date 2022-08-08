#pragma once
#ifndef NODE_H
#define NODE_H

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


#endif // !NODE_H

