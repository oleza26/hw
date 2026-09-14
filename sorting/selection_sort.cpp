#include "selection_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void selection_sort(std::vector<type>& array) {
	for (size_t i = 0; i < array.size(); ++i) {
		type mini = array[i];
		int index = i;
		for (size_t j = i; j < array.size(); ++j) {
			if (array[j] < mini) {
				mini = array[j];
				index = j;
			}
		}
		array[index] = array[i];
		array[i] = mini;
	}
}

template void selection_sort<int>(std::vector<int>& array);
template void selection_sort<double>(std::vector<double>& array);