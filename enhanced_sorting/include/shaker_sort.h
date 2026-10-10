#pragma once
#include <vector>
#include <cstddef>
#include <algorithm>

namespace enhanced_sorting {

    // Шейкерная (двунаправленная пузырьковая) сортировка.
    // Лучший случай — O(n), средний и худший — O(n^2).
    template <typename T>
    void shakerSort(std::vector<T>& arr) {
        if (arr.size() < 2) return;

        std::size_t left = 0;
        std::size_t right = arr.size() - 1;
        bool swapped = true;

        while (swapped) {
            swapped = false;

            // Проход слева направо: "тяжёлые" элементы уходят вправо
            for (std::size_t i = left; i < right; ++i) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;

            swapped = false;
            --right;  // правый край уже отсортирован

            // Проход справа налево: "лёгкие" элементы уходят влево
            for (std::size_t i = right; i > left; --i) {
                if (arr[i - 1] > arr[i]) {
                    std::swap(arr[i - 1], arr[i]);
                    swapped = true;
                }
            }
            ++left;  // левый край уже отсортирован
        }
    }

} // namespace enhanced_sorting