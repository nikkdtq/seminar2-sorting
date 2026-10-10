#include <catch.hpp>
#include <iostream>
#include "insertion_sort.h"
#include "selection_sort.h"
#include "exchange_sort.h"
#include "bubble_sort.h"
#include "optimized_bubble_sort.h"


TEST_CASE("Insertion sort: empty array stays empty") {
    // Arrange
    std::vector<int> arr;

    // Act
    insertion_sort(arr);

    // Assert
    REQUIRE(arr.empty());
}

TEST_CASE("Insertion sort: single element stays the same") {
    std::vector<int> arr{ 42 };
    insertion_sort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 42);
}

TEST_CASE("Insertion sort: reverse-ordered array becomes sorted") {
    std::vector<int> arr{ 5, 4, 3, 2, 1 };
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Insertion sort: already sorted array remains sorted") {
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    insertion_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Insertion sort: works with doubles") {
    std::vector<double> arr{ 3.5, 1.2, 2.8 };
    insertion_sort(arr);
    REQUIRE(arr[0] == Approx(1.2));
    REQUIRE(arr[1] == Approx(2.8));
    REQUIRE(arr[2] == Approx(3.5));
}

// -------------------- SELECTION SORT --------------------

TEST_CASE("Selection sort: empty array stays empty") {
    std::vector<int> arr;
    selection_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Selection sort: single element stays the same") {
    std::vector<int> arr{ 7 };
    selection_sort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 7);
}

TEST_CASE("Selection sort: reverse-ordered array becomes sorted") {
    std::vector<int> arr{ 9, 7, 5, 3, 1 };
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 3, 5, 7, 9 });
}

TEST_CASE("Selection sort: already sorted array remains sorted") {
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    selection_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Selection sort: works with doubles") {
    std::vector<double> arr{ 3.5, 1.2, 2.8 };
    selection_sort(arr);
    REQUIRE(arr[0] == Approx(1.2));
    REQUIRE(arr[1] == Approx(2.8));
    REQUIRE(arr[2] == Approx(3.5));
}

// -------------------- EXCHANGE SORT --------------------

TEST_CASE("Exchange sort: empty array stays empty") {
    std::vector<int> arr;
    exchange_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Exchange sort: single element stays the same") {
    std::vector<int> arr{ 3 };
    exchange_sort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 3);
}

TEST_CASE("Exchange sort: reverse-ordered array becomes sorted") {
    std::vector<int> arr{ 5, 4, 3, 2, 1 };
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Exchange sort: already sorted array remains sorted") {
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    exchange_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Exchange sort: works with doubles") {
    std::vector<double> arr{ 3.5, 1.2, 2.8 };
    exchange_sort(arr);
    REQUIRE(arr[0] == Approx(1.2));
    REQUIRE(arr[1] == Approx(2.8));
    REQUIRE(arr[2] == Approx(3.5));
}

// -------------------- BUBBLE SORT --------------------

TEST_CASE("Bubble sort: empty array stays empty") {
    std::vector<int> arr;
    bubble_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Bubble sort: single element stays the same") {
    std::vector<int> arr{ 11 };
    bubble_sort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 11);
}

TEST_CASE("Bubble sort: reverse-ordered array becomes sorted") {
    std::vector<int> arr{ 5, 4, 3, 2, 1 };
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Bubble sort: already sorted array remains sorted") {
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Bubble sort: works with doubles") {
    std::vector<double> arr{ 3.5, 1.2, 2.8 };
    bubble_sort(arr);
    REQUIRE(arr[0] == Approx(1.2));
    REQUIRE(arr[1] == Approx(2.8));
    REQUIRE(arr[2] == Approx(3.5));
}

// -------------------- OPTIMIZED BUBBLE SORT --------------------

TEST_CASE("Optimized bubble sort: empty array stays empty") {
    std::vector<int> arr;
    optimized_bubble_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("Optimized bubble sort: single element stays the same") {
    std::vector<int> arr{ 5 };
    optimized_bubble_sort(arr);
    REQUIRE(arr.size() == 1);
    REQUIRE(arr[0] == 5);
}

TEST_CASE("Optimized bubble sort: reverse-ordered array becomes sorted") {
    std::vector<int> arr{ 5, 4, 3, 2, 1 };
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Optimized bubble sort: already sorted array remains sorted") {
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    optimized_bubble_sort(arr);
    REQUIRE(arr == std::vector<int>{ 1, 2, 3, 4, 5 });
}

TEST_CASE("Optimized bubble sort: works with doubles") {
    std::vector<double> arr{ 3.5, 1.2, 2.8 };
    optimized_bubble_sort(arr);
    REQUIRE(arr[0] == Approx(1.2));
    REQUIRE(arr[1] == Approx(2.8));
    REQUIRE(arr[2] == Approx(3.5));
}


TEST_CASE("Individual variant 5: all sorts produce the same sorted array") {
    std::vector<int> source{ 14, 6, 12, 18, 5, 1, 11, 3 };
    std::vector<int> expected{ 1, 3, 5, 6, 11, 12, 14, 18 };

    std::vector<int> a1 = source;
    std::vector<int> a2 = source;
    std::vector<int> a3 = source;
    std::vector<int> a4 = source;
    std::vector<int> a5 = source;

    insertion_sort(a1);
    selection_sort(a2);
    exchange_sort(a3);
    bubble_sort(a4);
    optimized_bubble_sort(a5);

    REQUIRE(a1 == expected);
    REQUIRE(a2 == expected);
    REQUIRE(a3 == expected);
    REQUIRE(a4 == expected);
    REQUIRE(a5 == expected);

    // ---------- Печать до/после для наглядности ----------
    auto print = [](const std::vector<int>& v) {
        std::cout << "[ ";
        for (int x : v) std::cout << x << " ";
        std::cout << "]\n";
        };

    std::cout << "Source:   "; print(source);
    std::cout << "Expected: "; print(expected);
    std::cout << "Insertion: "; print(a1);
    std::cout << "Selection: "; print(a2);
    std::cout << "Exchange:  "; print(a3);
    std::cout << "Bubble:    "; print(a4);
    std::cout << "Optimized: "; print(a5);
}