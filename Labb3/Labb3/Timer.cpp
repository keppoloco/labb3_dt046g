#include "Timer.h"
#include <iostream>

double time_it(bool(*search)(std::vector<int>::iterator, std::vector<int>::iterator, const int&), std::vector<int>::iterator first, std::vector<int>::iterator last, const int& number)
{
    auto start = std::chrono::high_resolution_clock::now();
    search(first, last, number);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    return total.count();
}

double time_it(bool(*search)(std::vector<HashNode*>::iterator, std::vector<HashNode*>::iterator, const int&), std::vector<HashNode*>::iterator first, std::vector<HashNode*>::iterator last, const int& number)
{
    auto start = std::chrono::high_resolution_clock::now();
    search(first, last, number);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    return total.count();
}

double time_it(bool(*search)(Node*, const int&), Node* root, const int& number)
{
    auto start = std::chrono::high_resolution_clock::now();
    search(root, number);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> total = (stop - start);
    return total.count();
}

