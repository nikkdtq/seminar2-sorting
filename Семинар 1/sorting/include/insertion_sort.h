#pragma once
#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& arr) { // параметр шаблона Т-type
	for (std::size_t i = 1; i < arr.size(); ++i) { // считаем что 1 эл уже отсорт поэтому i = 1  
		T key = arr[i];// запоминаем тек элемент, key - эл кот нужно вставить 
		std::size_t j = i;
		while (j > 0 && arr[j - 1] > key) { // пока эл слева больше вставляемого key
			arr[j] = arr[j - 1];// сдвигаем элемент вправо
			--j;// уходим влево
		}
		arr[j] = key;
	}

}
//// Сортировка массива методом простой вставки