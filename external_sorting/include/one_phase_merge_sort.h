#pragma once
#include <string>
#include <cstddef>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

namespace external_sorting {

    namespace detail {

        template <typename T>
        void mergeFilesOnePhase(const std::string& fileA,
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

    } // namespace detail

    // Однофазная сортировка простым слиянием.
    //
    // Блоки сортируются и СРАЗУ сливаются с уже накопленным результатом.
    // Требует меньше временных файлов, чем двухфазная.
    template <typename T>
    void onePhaseMergeSort(const std::string& inputFile,
        const std::string& outputFile,
        std::size_t blockSize)
    {
        std::ifstream in(inputFile);

        const std::string current = "one_phase_current.txt";
        bool hasCurrent = false;

        std::size_t blockIndex = 0;
        std::size_t mergeIndex = 0;

        while (in) {
            std::vector<T> buffer;
            buffer.reserve(blockSize);

            T value;
            while (buffer.size() < blockSize && (in >> value)) {
                buffer.push_back(value);
            }
            if (buffer.empty()) break;

            std::sort(buffer.begin(), buffer.end());

            std::string blockFile = "one_phase_block_" +
                std::to_string(blockIndex++) + ".txt";
            {
                std::ofstream out(blockFile);
                for (const T& x : buffer) out << x << '\n';
            }

            if (!hasCurrent) {
                std::rename(blockFile.c_str(), current.c_str());
                hasCurrent = true;
            }
            else {
                std::string merged = "one_phase_merged_" +
                    std::to_string(mergeIndex++) + ".txt";
                detail::mergeFilesOnePhase<T>(current, blockFile, merged);
                std::remove(current.c_str());
                std::remove(blockFile.c_str());
                std::rename(merged.c_str(), current.c_str());
            }
        }

        if (!hasCurrent) {
            std::ofstream out(outputFile);
            return;
        }
        std::rename(current.c_str(), outputFile.c_str());
    }

} // namespace external_sorting