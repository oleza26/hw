#include "bubble_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void bubble_sort(std::vector<type>& array) {
	for (size_t i = 0; i < array.size(); ++i) {
		for (size_t j = 0; j + 1 < array.size(); ++j) {
			if (array[j + 1] < array[j]) {
				type temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

template void bubble_sort<int>(std::vector<int>& array);
template void bubble_sort<double>(std::vector<double>& array);