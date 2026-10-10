#pragma once
#include <vector>
#include <cstddef>

namespace enhanced_sorting {
	template <typename T> //фция работает с любым типом 
	void binaryInsertionSort(std::vector<T>& arr) { //arr передаётся по ссылке (&), чтобы менять оригинал, а не копию.
		//проверка на мал массив
		const std::size_t n = arr.size();
		if (n < 2) return;

		for (std::size_t i = 1; i < n; ++i) {
			T key = arr[i];

			// Бинарный поиск позиции для вставки key в arr[0..i-1]
			std::size_t left = 0;
			std::size_t right = i;
			while (left < right) {
				std::size_t mid = left + (right - left) / 2;
				if (arr[mid] <= key) {
					left = mid + 1;
				}
				else {
					right = mid;
				}
			}

			for (std::size_t j = i; j > left; --j) {
				arr[j] = arr[j - 1];
			}
			arr[left] = key;
		}
	}
}