#include <catch.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include "one_phase_merge_sort.h"

using namespace external_sorting;

template <typename T>
void writeFile(const std::string& path, const std::vector<T>& data) {
    std::ofstream out(path);
    for (const T& x : data) out << x << '\n';
}

template <typename T>
std::vector<T> readFile(const std::string& path) {
    std::ifstream in(path);
    std::vector<T> result;
    T x;
    while (in >> x) result.push_back(x);
    return result;
}

TEST_CASE("One-phase merge sort: empty file") {
    const std::string inFile = "test_op_empty_in.txt";
    const std::string outFile = "test_op_empty_out.txt";
    writeFile<int>(inFile, {});
    onePhaseMergeSort<int>(inFile, outFile, 2);
    REQUIRE(readFile<int>(outFile).empty());
    std::remove(inFile.c_str());
    std::remove(outFile.c_str());
}

TEST_CASE("One-phase merge sort: single element") {
    const std::string inFile = "test_op_one_in.txt";
    const std::string outFile = "test_op_one_out.txt";
    writeFile<int>(inFile, { 42 });
    onePhaseMergeSort<int>(inFile, outFile, 2);
    REQUIRE(readFile<int>(outFile) == std::vector<int>{ 42 });
    std::remove(inFile.c_str());
    std::remove(outFile.c_str());
}

TEST_CASE("One-phase merge sort: reverse-ordered") {
    const std::string inFile = "test_op_rev_in.txt";
    const std::string outFile = "test_op_rev_out.txt";
    writeFile<int>(inFile, { 5, 4, 3, 2, 1 });
    onePhaseMergeSort<int>(inFile, outFile, 2);
    REQUIRE(readFile<int>(outFile) == std::vector<int>{ 1, 2, 3, 4, 5 });
    std::remove(inFile.c_str());
    std::remove(outFile.c_str());
}

TEST_CASE("One-phase merge sort: already sorted") {
    const std::string inFile = "test_op_sorted_in.txt";
    const std::string outFile = "test_op_sorted_out.txt";
    writeFile<int>(inFile, { 1, 2, 3, 4, 5 });
    onePhaseMergeSort<int>(inFile, outFile, 2);
    REQUIRE(readFile<int>(outFile) == std::vector<int>{ 1, 2, 3, 4, 5 });
    std::remove(inFile.c_str());
    std::remove(outFile.c_str());
}

TEST_CASE("One-phase merge sort: works with doubles") {
    const std::string inFile = "test_op_dbl_in.txt";
    const std::string outFile = "test_op_dbl_out.txt";
    writeFile<double>(inFile, { 3.5, 1.2, 2.8 });
    onePhaseMergeSort<double>(inFile, outFile, 2);
    auto r = readFile<double>(outFile);
    REQUIRE(r.size() == 3);
    REQUIRE(r[0] == Approx(1.2));
    REQUIRE(r[1] == Approx(2.8));
    REQUIRE(r[2] == Approx(3.5));
    std::remove(inFile.c_str());
    std::remove(outFile.c_str());
}

TEST_CASE("One-phase merge sort: many elements, small blocks") {
    const std::string inFile = "test_op_many_in.txt";
    const std::string outFile = "test_op_many_out.txt";
    std::vector<int> data;
    for (int i = 100; i >= 1; --i) data.push_back(i);
    writeFile<int>(inFile, data);
    onePhaseMergeSort<int>(inFile, outFile, 10);
    auto r = readFile<int>(outFile);
    REQUIRE(r.size() == 100);
    for (std::size_t i = 0; i < 100; ++i) {
        REQUIRE(r[i] == static_cast<int>(i + 1));
    }
    std::remove(inFile.c_str());
    std::remove(outFile.c_str());
}

TEST_CASE("One-phase merge sort: duplicates") {
    const std::string inFile = "test_op_dup_in.txt";
    const std::string outFile = "test_op_dup_out.txt";
    writeFile<int>(inFile, { 3, 1, 3, 2, 1, 2 });
    onePhaseMergeSort<int>(inFile, outFile, 2);
    REQUIRE(readFile<int>(outFile) == std::vector<int>{ 1, 1, 2, 2, 3, 3 });
    std::remove(inFile.c_str());
    std::remove(outFile.c_str());
}