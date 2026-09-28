#include "shaker_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void shaker_sort(std::vector<type>& array) {
	int l = 0;
	int r = array.size() - 1;
	while (l < r) {
		for (size_t j = l; j < r; ++j) {
			if (array[j + 1] < array[j]) {
				type t = array[j + 1];
				array[j + 1] = array[j];
				array[j] = t;
			}
		}
		r--;
		for (size_t j = r; j > l; --j) {
			if (array[j - 1] > array[j]) {
				type t = array[j - 1];
				array[j - 1] = array[j];
				array[j] = t;
			}
		}
		l++;
	}
}

template void shaker_sort<int>(std::vector<int>& array);
template void shaker_sort<double>(std::vector<double>& array);