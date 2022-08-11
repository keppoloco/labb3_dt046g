#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <algorithm>
#include <vector>

double time_it(bool(*search)(std::vector<int>::iterator, std::vector<int>::iterator, const int&), std::vector<int>::iterator, std::vector<int>::iterator, const int& number);

#endif