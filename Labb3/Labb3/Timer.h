#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <algorithm>
#include <vector>
#include "Node.h"

double time_it(bool(*search)(std::vector<int>::iterator, std::vector<int>::iterator, const int&), std::vector<int>::iterator, std::vector<int>::iterator, const int& number);
double time_it(bool(*search)(std::vector<HashNode*>::iterator, std::vector<HashNode*>::iterator, const int&), std::vector<HashNode*>::iterator, std::vector<HashNode*>::iterator, const int& number);
double time_it(bool(*search)(Node*, const int&), Node*, const int& number);

#endif