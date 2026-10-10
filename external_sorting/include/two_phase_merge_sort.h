#pragma once
#include <string>
#include <cstddef>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

namespace external_sorting {

    namespace detail {

        // Слить два отсортированных файла в один (построчное сравнение).
        template <typename T>
        void mergeFiles(const std::string& fileA,
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

        inline std::string tempFileName(std::size_t index) {
            return "temp_" + std::to_string(index) + ".txt";
        }

    } // namespace detail

    // Двухфазная сортировка простым слиянием.
    //
    // Фаза 1: разбить входной файл на блоки по blockSize,
    //         каждый отсортировать в памяти и записать во временный файл.
    // Фаза 2: попарно слить временные файлы, пока не останется один.
    template <typename T>
    void twoPhaseMergeSort(const std::string& inputFile,
        const std::string& outputFile,
        std::size_t blockSize)
    {
        // ---------- Фаза 1 ----------
        std::ifstream in(inputFile);
        std::vector<std::string> tempFiles;

        std::size_t fileIndex = 0;
        while (in) {
            std::vector<T> buffer;
            buffer.reserve(blockSize);

            T value;
            while (buffer.size() < blockSize && (in >> value)) {
                buffer.push_back(value);
            }
            if (buffer.empty()) break;

            std::sort(buffer.begin(), buffer.end());

            std::string tempName = detail::tempFileName(fileIndex++);
            std::ofstream out(tempName);
            for (const T& x : buffer) out << x << '\n';
            tempFiles.push_back(tempName);
        }

        if (tempFiles.empty()) {
            std::ofstream out(outputFile);
            return;
        }
        if (tempFiles.size() == 1) {
            std::ifstream src(tempFiles[0]);
            std::ofstream dst(outputFile);
            dst << src.rdbuf();
            std::remove(tempFiles[0].c_str());
            return;
        }

        // ---------- Фаза 2 ----------
        std::size_t mergeRound = 0;
        while (tempFiles.size() > 1) {
            std::vector<std::string> nextRound;

            for (std::size_t i = 0; i + 1 < tempFiles.size(); i += 2) {
                std::string merged = "merge_" + std::to_string(mergeRound) +
                    "_" + std::to_string(i) + ".txt";
                detail::mergeFiles<T>(tempFiles[i], tempFiles[i + 1], merged);
                std::remove(tempFiles[i].c_str());
                std::remove(tempFiles[i + 1].c_str());
                nextRound.push_back(merged);
            }
            if (tempFiles.size() % 2 == 1) {
                nextRound.push_back(tempFiles.back());
            }

            tempFiles = std::move(nextRound);
            ++mergeRound;
        }

        std::rename(tempFiles[0].c_str(), outputFile.c_str());
    }

} // namespace external_sorting