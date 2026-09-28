#include "shell_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void shell_sort(std::vector<type>& array) {
    int n = array.size();
    if (n <= 1) return;
    
    int g = n / 2;
    while (g > 0) {
        for (size_t i = g; i < n; ++i) {
            type t = array[i];
            int j = i;
            while (j >= g && array[j - g] > t) {
                array[j] = array[j - g];
                j -= g;
            }
            array[j] = t;
        }
        g /= 2;
    }
}

template void shell_sort<int>(std::vector<int>& array);
template void shell_sort<double>(std::vector<double>& array);