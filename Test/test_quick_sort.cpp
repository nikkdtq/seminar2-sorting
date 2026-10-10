#include <catch.hpp>
#include "quick_sort.h"

using enhanced_sorting::quickSort;

TEST_CASE("Quick sort: empty array stays empty") {
    std::vector<int> arr;
    quickSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Quick sort: single element stays the same") {
    std::vector<int> arr{ 7 };
    quickSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 7);
}

TEST_CASE("Quick sort: reverse-ordered array becomes sorted") {
    std::vector<int> arr{ 9, 7, 5, 3, 1 };
    quickSort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 3, 5, 7, 9 });
}

TEST_CASE("Quick sort: already sorted array remains sorted") {
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    quickSort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Quick sort: works with doubles") {
    std::vector<double> arr{ 3.5, 1.2, 2.8 };
    quickSort(arr);
    REQUIRE(arr[0] == Approx(1.2));
    REQUIRE(arr[1] == Approx(2.8));
    REQUIRE(arr[2] == Approx(3.5));
}

TEST_CASE("Quick sort: handles duplicates") {
    std::vector<int> arr{ 3, 1, 3, 2, 1, 2 };
    quickSort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 1, 2, 2, 3, 3 });
}

TEST_CASE("Quick sort: negative numbers and zero") {
    std::vector<int> arr{ -3, 5, -1, 0, 2, -7 };
    quickSort(arr);
    REQUIRE(arr == std::vector<int>{ -7, -3, -1, 0, 2, 5 });
}