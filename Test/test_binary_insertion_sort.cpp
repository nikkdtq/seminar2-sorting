#include <catch.hpp>
#include <vector>
#include "binary_insertion_sort.h"

using namespace enhanced_sorting;

// ============================================================
// “есты дл€ binaryInsertionSort
// ============================================================

TEST_CASE("binaryInsertionSort: обычный неупор€доченный массив", "[binary]") {
    std::vector<int> data = { 5, 2, 9, 1, 5, 6 };
    binaryInsertionSort(data);
    REQUIRE(data == std::vector<int>{1, 2, 5, 5, 6, 9});
}

TEST_CASE("binaryInsertionSort: пустой массив", "[binary]") {
    std::vector<int> data;
    binaryInsertionSort(data);
    REQUIRE(data.empty());
}

TEST_CASE("binaryInsertionSort: один элемент", "[binary]") {
    std::vector<int> data = { 42 };
    binaryInsertionSort(data);
    REQUIRE(data == std::vector<int>{42});
}

TEST_CASE("binaryInsertionSort: уже отсортированный массив", "[binary]") {
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    binaryInsertionSort(data);
    REQUIRE(data == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("binaryInsertionSort: обратный пор€док", "[binary]") {
    std::vector<int> data = { 5, 4, 3, 2, 1 };
    binaryInsertionSort(data);
    REQUIRE(data == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("binaryInsertionSort: double", "[binary]") {
    std::vector<double> data = { 3.14, 1.41, 2.71, 0.58 };
    binaryInsertionSort(data);
    REQUIRE(data[0] == Approx(0.58));
    REQUIRE(data[1] == Approx(1.41));
    REQUIRE(data[2] == Approx(2.71));
    REQUIRE(data[3] == Approx(3.14));
}

TEST_CASE("binaryInsertionSort: дубликаты", "[binary]") {
    std::vector<int> data = { 7, 7, 7, 7 };
    binaryInsertionSort(data);
    REQUIRE(data == std::vector<int>{7, 7, 7, 7});
}