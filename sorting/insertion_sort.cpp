#include "insertion_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void insertion_sort(std::vector<type>& array) {
	for (size_t i = 1; i < array.size(); ++i) {
		type s = array[i];
		int j = i - 1; 
		while (j >= 0 && array[j] > s) {
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = s;
	}
}

template void insertion_sort<int>(std::vector<int>&);
template void insertion_sort<double>(std::vector<double>&);
