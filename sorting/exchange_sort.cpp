#include "exchange_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void exchange_sort(std::vector<type>& array) {
	for (size_t i = 0; i < array.size(); ++i) {
		for (size_t j = i + 1; j < array.size(); ++j) {
			if (array[j] < array[i]) {
				type temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}

template void exchange_sort<int>(std::vector<int>& array);
template void exchange_sort<double>(std::vector<double>& array);