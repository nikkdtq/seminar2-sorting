#pragma once

#include <vector>

template <typename T>
void optimized_bubble_sort(std::vector<T>& arr) {
    for (std::size_t i = 0; i + 1 < arr.size(); ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j + 1 < arr.size() - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
