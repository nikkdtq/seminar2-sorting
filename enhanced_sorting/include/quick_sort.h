#pragma once
#include <vector>
#include <cstddef>
#include <algorithm>

namespace enhanced_sorting {

    namespace detail {

        // –азбиение ’оара с опорным элементом в середине.
        // ¬озвращает индекс, раздел€ющий массив на две части:
        //   arr[left .. p]    Ч <= pivot
        //   arr[p+1 .. right] Ч >= pivot
        template <typename T>
        std::size_t partition(std::vector<T>& arr,
            std::size_t left,
            std::size_t right)
        {
            // ќпорный элемент Ч середина отрезка.
            // ≈сли вз€ть крайний, на отсортированных данных получим O(n^2).
            T pivot = arr[left + (right - left) / 2];

            std::size_t i = left;
            std::size_t j = right;

            while (true) {
                // »щем слева элемент >= pivot
                while (arr[i] < pivot) ++i;
                // »щем справа элемент <= pivot
                while (arr[j] > pivot) --j;

                if (i >= j) return j;

                std::swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }

        // –екурсивна€ часть быстрой сортировки.
        template <typename T>
        void quickSortImpl(std::vector<T>& arr,
            std::size_t left,
            std::size_t right)
        {
            if (left >= right) return;   // 0 или 1 элемент Ч нечего сортировать

            std::size_t p = partition(arr, left, right);

            if (p > 0) {
                quickSortImpl(arr, left, p);
            }
            quickSortImpl(arr, p + 1, right);
        }

    } // namespace detail

    // Ѕыстра€ сортировка (QuickSort).
    //
    // »де€:
    //   1. ¬ыбираем опорный элемент (pivot).
    //   2. –азбиваем массив: слева Ч элементы меньше pivot,
    //      справа Ч больше.
    //   3. –екурсивно сортируем левую и правую части.
    //
    // —ложность:
    //   - средний случай: O(n log n);
    //   - худший (массив уже отсортирован, плохой выбор pivot): O(n^2);
    //   - лучший: O(n log n).
    // ѕам€ть: O(log n) из-за стека рекурсии.
    template <typename T>
    void quickSort(std::vector<T>& arr) {
        if (arr.size() < 2) return;
        detail::quickSortImpl(arr, 0, arr.size() - 1);
    }

} // namespace enhanced_sorting