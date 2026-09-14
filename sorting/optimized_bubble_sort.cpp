#include "optimized_bubble_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void optimized_bubble_sort(std::vector<type>& array) {
	for (size_t i = 0; i < array.size(); ++i) {
		int flag = 0;
		for (size_t j = 0; j + 1 < array.size(); ++j) {
			if (array[j + 1] < array[j]) {
				type temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

template void optimized_bubble_sort<int>(std::vector<int>& array);
template void optimized_bubble_sort<double>(std::vector<double>& array);