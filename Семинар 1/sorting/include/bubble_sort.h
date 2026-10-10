#pragma once
#include <vector>

template <typename T>
void bubble_sort(std::vector<T>& arr) {
    for (std::size_t i = 0; i + 1 < arr.size(); ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j + 1 < arr.size() - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;                  // ← НОВОЕ
            }
        }
        if (!swapped) break;                     // ← НОВОЕ
    }
}
//СОРТИРОВКА ПРОСТЫМ ОБМЕНОМ(1 СПОСОБ)

//Многократно проходим по вектору, сравниваем каждую пару соседей и меняем
// их местами, если они стоят в неправильном порядке.