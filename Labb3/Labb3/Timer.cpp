#include "Timer.h"

double time_it(bool(*search)(std::vector<int>::iterator, std::vector<int>::iterator, const int&), std::vector<int>::iterator first, std::vector<int>::iterator last, const int& number)
{
    auto start = std::chrono::high_resolution_clock::now();
    search(first, last, number);
    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
}

