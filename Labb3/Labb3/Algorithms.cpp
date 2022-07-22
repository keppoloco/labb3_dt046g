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
    return false;
}
