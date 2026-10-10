#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>

namespace external_sorting {

    namespace detail {

        template <typename T>
        void mergeFilesNatural(const std::string& fileA,
            const std::string& fileB,
            const std::string& outFile)
        {
            std::ifstream inA(fileA);
            std::ifstream inB(fileB);
            std::ofstream out(outFile);

            T a, b;
            bool hasA = static_cast<bool>(inA >> a);
            bool hasB = static_cast<bool>(inB >> b);

            while (hasA && hasB) {
                if (a <= b) {
                    out << a << '\n';
                    hasA = static_cast<bool>(inA >> a);
                }
                else {
                    out << b << '\n';
                    hasB = static_cast<bool>(inB >> b);
                }
            }
            while (hasA) { out << a << '\n'; hasA = static_cast<bool>(inA >> a); }
            while (hasB) { out << b << '\n'; hasB = static_cast<bool>(inB >> b); }
        }

        // Разбить файл на серии: каждая серия — возрастающая
        // последовательность (arr[i] <= arr[i+1]).
        template <typename T>
        std::vector<std::string> splitIntoRuns(const std::string& inputFile)
        {
            std::ifstream in(inputFile);
            std::vector<std::string> runs;

            T prev;
            if (!(in >> prev)) return runs;

            std::size_t runIndex = 0;
            std::string runFile = "run_" + std::to_string(runIndex) + ".txt";
            std::ofstream out(runFile);
            out << prev << '\n';

            T curr;
            while (in >> curr) {
                if (curr < prev) {
                    out.close();
                    runs.push_back(runFile);
                    ++runIndex;
                    runFile = "run_" + std::to_string(runIndex) + ".txt";
                    out.open(runFile);
                }
                out << curr << '\n';
                prev = curr;
            }
            out.close();
            runs.push_back(runFile);
            return runs;
        }

    } // namespace detail

    // Естественная сортировка слиянием.
    //
    // Использует УЖЕ существующие упорядоченные серии во входном файле.
    // Если данные частично отсортированы — работает быстрее O(n log n).
    template <typename T>
    void naturalMergeSort(const std::string& inputFile,
        const std::string& outputFile)
    {
        auto runs = detail::splitIntoRuns<T>(inputFile);

        if (runs.empty()) {
            std::ofstream out(outputFile);
            return;
        }
        if (runs.size() == 1) {
            std::rename(runs[0].c_str(), outputFile.c_str());
            return;
        }

        std::size_t round = 0;
        while (runs.size() > 1) {
            std::vector<std::string> next;

            for (std::size_t i = 0; i + 1 < runs.size(); i += 2) {
                std::string merged = "natural_merge_" +
                    std::to_string(round) + "_" +
                    std::to_string(i) + ".txt";
                detail::mergeFilesNatural<T>(runs[i], runs[i + 1], merged);
                std::remove(runs[i].c_str());
                std::remove(runs[i + 1].c_str());
                next.push_back(merged);
            }
            if (runs.size() % 2 == 1) {
                next.push_back(runs.back());
            }
            runs = std::move(next);
            ++round;
        }

        std::rename(runs[0].c_str(), outputFile.c_str());
    }

} // namespace external_sorting