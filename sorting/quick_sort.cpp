#include "quick_sort.h"
#include <iostream>
#include <vector>

template <typename type>
int partition(std::vector<type>& array, int l, int h) {
    type pivot = array[l + (h - l) / 2];
    int i = l;
    int j = h;

    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i <= j) {
            type t = array[i];
            array[i] = array[j];
            array[j] = t;

            i++;
            j--;
        }
    }
    return i;
}

template <typename type>
void quick_sort(std::vector<type>& array, int l, int h) {
    if (l < h) {
        int pivot_index = partition(array, l, h);

        quick_sort(array, l, pivot_index - 1);
        quick_sort(array, pivot_index, h);
    }
}

template <typename type>
void quick_sort(std::vector<type>& array) {
    if (!array.empty()) {
        quick_sort(array, 0, static_cast<int>(array.size()) - 1);
    }
}

template int partition<int>(std::vector<int>&, int, int);
template void quick_sort<int>(std::vector<int>&, int, int);
template void quick_sort<int>(std::vector<int>&);


template int partition<double>(std::vector<double>&, int, int);
template void quick_sort<double>(std::vector<double>&, int, int);
template void quick_sort<double>(std::vector<double>&);