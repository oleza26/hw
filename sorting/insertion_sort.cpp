#include "insertion_sort.h"
#include <iostream>
#include <vector>

template <typename type>
void insertion_sort(std::vector<type>& array) {
	for (size_t i = 0; i < array.size(); ++i) {
		type s = array[i]; // сохраняем передвигаемый элемент, потому что мы его затираем при сдвиге
		int j = i - 1; // индекс последнего отсортированного элемента

		// в while сдвигаем все элементы большие s вправо и освобождаем место под s
		while (j >= 0 && array[j] > s) {
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = s; // вставляем сортируемое число s в нужное место
	}
}

template void insertion_sort<int>(std::vector<int>&);
template void insertion_sort<double>(std::vector<double>&);
