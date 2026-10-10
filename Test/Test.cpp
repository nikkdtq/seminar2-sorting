#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "binary_insertion_sort.h"
#include "shaker_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"

using namespace enhanced_sorting;

// ============================================================
// Индивидуальный вариант 5
// ============================================================

TEST_CASE("Individual variant 5: all sorts produce the same sorted array",
    "[variant5]") {
    std::vector<int> source{ 14, 6, 12, 18, 5, 1, 11, 3 };
    std::vector<int> expected{ 1, 3, 5, 6, 11, 12, 14, 18 };

    std::vector<int> a_binary = source;
    std::vector<int> a_shaker = source;
    std::vector<int> a_shell = source;
    std::vector<int> a_quick = source;

    binaryInsertionSort(a_binary);
    shakerSort(a_shaker);
    shellSort(a_shell);
    quickSort(a_quick);

    REQUIRE(a_binary == expected);
    REQUIRE(a_shaker == expected);
    REQUIRE(a_shell == expected);
    REQUIRE(a_quick == expected);

    // ---------- Печать до/после ----------
    auto print = [](const std::string& label, const std::vector<int>& v) {
        std::cout << std::left << std::setw(16) << label << ": [ ";
        for (int x : v) std::cout << x << " ";
        std::cout << "]\n";
        };

    std::cout << "\n";
    print("Source", source);
    print("Expected", expected);
    print("BinaryInsertion", a_binary);
    print("Shaker", a_shaker);
    print("Shell", a_shell);
    print("Quick", a_quick);
    std::cout << "==================================================\n";
}