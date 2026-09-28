#include <vector>
#include "binary_insertion_sort.h"

template <typename type>
void binary_insertion_sort(std::vector<type>& array) {
    for (size_t i = 1; i < array.size(); ++i) {
        type k = array[i];
        int l = 0;
        int r = i - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (array[m] <= k) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        int j = i - 1;
        while (j >= l) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = k;
    }
}

template void binary_insertion_sort(std::vector<int>& array);
template void binary_insertion_sort(std::vector<double>& array);
