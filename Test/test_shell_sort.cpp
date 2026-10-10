#include <catch.hpp>
#include "shell_sort.h"

using enhanced_sorting::shellSort;

TEST_CASE("Shell sort: empty array stays empty") {
    std::vector<int> arr;
    shellSort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Shell sort: single element stays the same") {
    std::vector<int> arr{ 42 };
    shellSort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("Shell sort: reverse-ordered array becomes sorted") {
    std::vector<int> arr{ 5, 4, 3, 2, 1 };
    shellSort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Shell sort: already sorted array remains sorted") {
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    shellSort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Shell sort: works with doubles") {
    std::vector<double> arr{ 3.5, 1.2, 2.8 };
    shellSort(arr);
    REQUIRE(arr[0] == Approx(1.2));
    REQUIRE(arr[1] == Approx(2.8));
    REQUIRE(arr[2] == Approx(3.5));
}

TEST_CASE("Shell sort: handles duplicates") {
    std::vector<int> arr{ 3, 1, 3, 2, 1, 2 };
    shellSort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 1, 2, 2, 3, 3 });
}

TEST_CASE("Shell sort: negative numbers and zero") {
    std::vector<int> arr{ -3, 5, -1, 0, 2, -7 };
    shellSort(arr);
    REQUIRE(arr == std::vector<int>{ -7, -3, -1, 0, 2, 5 });
}