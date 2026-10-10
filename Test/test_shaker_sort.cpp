#include <catch.hpp>
#include <vector>
#include "shaker_sort.h"

using namespace enhanced_sorting;

// ============================================================
// “есты дл€ shakerSort
// ============================================================

TEST_CASE("shakerSort: обычный неупор€доченный массив", "[shaker]") {
    std::vector<int> data = { 5, 2, 9, 1, 5, 6 };
    shakerSort(data);
    REQUIRE(data == std::vector<int>{1, 2, 5, 5, 6, 9});
}

TEST_CASE("shakerSort: пустой массив", "[shaker]") {
    std::vector<int> data;
    shakerSort(data);
    REQUIRE(data.empty());
}

TEST_CASE("shakerSort: один элемент", "[shaker]") {
    std::vector<int> data = { 42 };
    shakerSort(data);
    REQUIRE(data == std::vector<int>{42});
}

TEST_CASE("shakerSort: уже отсортированный массив", "[shaker]") {
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    shakerSort(data);
    REQUIRE(data == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("shakerSort: обратный пор€док", "[shaker]") {
    std::vector<int> data = { 5, 4, 3, 2, 1 };
    shakerSort(data);
    REQUIRE(data == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("shakerSort: double", "[shaker]") {
    std::vector<double> data = { 3.14, 1.41, 2.71, 0.58 };
    shakerSort(data);
    REQUIRE(data[0] == Approx(0.58));
    REQUIRE(data[1] == Approx(1.41));
    REQUIRE(data[2] == Approx(2.71));
    REQUIRE(data[3] == Approx(3.14));
}

TEST_CASE("shakerSort: дубликаты", "[shaker]") {
    std::vector<int> data = { 4, 2, 4, 1, 2, 1 };
    shakerSort(data);
    REQUIRE(data == std::vector<int>{1, 1, 2, 2, 4, 4});
}