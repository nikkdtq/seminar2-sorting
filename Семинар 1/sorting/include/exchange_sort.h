#pragma once
#include <vector>

template <typename T>
void exchange_sort(std::vector<T>& arr) {
    for (std::size_t i = 0; i + 1 < arr.size(); ++i) {
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                T temp = arr[i]; // обмен местами 
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// аждый элемент сравниваетс€ со всеми, кто стоит справа, и если текущий больше Ч они мен€ютс€ местами.