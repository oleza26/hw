#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

template <typename T>
void natural_merge_sort(const std::string& inputFile);

// ==============================================================================
// Реализация шаблонной функции
// ==============================================================================
template <typename T>
void natural_merge_sort(const std::string& inputFile) {
    std::string temp1 = "temp1.bin";
    std::string temp2 = "temp2.bin";

    while (true) {
        // === ЭТАП 1: РАСПРЕДЕЛЕНИЕ ЕСТЕСТВЕННЫХ СЕРИЙ ===
        std::ifstream inSrc(inputFile, std::ios::binary);
        std::ofstream out1(temp1, std::ios::binary);
        std::ofstream out2(temp2, std::ios::binary);

        int runsCount = 0;
        std::vector<T> currentRun;
        std::ofstream* currentOut = &out1;

        T prevVal, currVal;
        bool hasData = false;

        if (inSrc.read(reinterpret_cast<char*>(&prevVal), sizeof(T))) {
            currentRun.push_back(prevVal);
            hasData = true;
        }

        while (inSrc.read(reinterpret_cast<char*>(&currVal), sizeof(T))) {
            if (currVal >= prevVal) {
                currentRun.push_back(currVal);
            }
            else {
                currentOut->write(reinterpret_cast<const char*>(currentRun.data()), currentRun.size() * sizeof(T));
                currentRun.clear();
                runsCount++;

                currentOut = (currentOut == &out1) ? &out2 : &out1;
                currentRun.push_back(currVal);
            }
            prevVal = currVal;
        }

        if (!currentRun.empty()) {
            currentOut->write(reinterpret_cast<const char*>(currentRun.data()), currentRun.size() * sizeof(T));
            runsCount++;
        }

        inSrc.close(); out1.close(); out2.close();

        if (runsCount <= 1) {
            break;
        }

        // === ЭТАП 2: СЛИЯНИЕ ЕСТЕСТВЕННЫХ СЕРИЙ ===
        std::ifstream in1(temp1, std::ios::binary);
        std::ifstream in2(temp2, std::ios::binary);
        std::ofstream outSrc(inputFile, std::ios::binary);

        while (in1 || in2) {
            std::vector<T> run1, run2;
            T val;

            // Читаем серию из temp1
            if (in1.read(reinterpret_cast<char*>(&val), sizeof(T))) {
                run1.push_back(val);
                while (in1.read(reinterpret_cast<char*>(&val), sizeof(T))) {
                    if (val >= run1.back()) {
                        run1.push_back(val);
                    }
                    else {
                        // ИСПРАВЛЕНО: явное приведение к знаковому типу std::streamoff
                        in1.seekg(-static_cast<std::streamoff>(sizeof(T)), std::ios::cur);
                        break;
                    }
                }
            }

            // Читаем серию из temp2
            if (in2.read(reinterpret_cast<char*>(&val), sizeof(T))) {
                run2.push_back(val);
                while (in2.read(reinterpret_cast<char*>(&val), sizeof(T))) {
                    if (val >= run2.back()) {
                        run2.push_back(val);
                    }
                    else {
                        // ИСПРАВЛЕНО: явное приведение к знаковому типу std::streamoff
                        in2.seekg(-static_cast<std::streamoff>(sizeof(T)), std::ios::cur);
                        break;
                    }
                }
            }

            if (run1.empty() && run2.empty()) break;

            // Встроенное слияние
            std::vector<T> merged;
            merged.reserve(run1.size() + run2.size());
            size_t i = 0, j = 0;
            while (i < run1.size() && j < run2.size()) {
                if (run1[i] <= run2[j]) merged.push_back(run1[i++]);
                else merged.push_back(run2[j++]);
            }
            while (i < run1.size()) merged.push_back(run1[i++]);
            while (j < run2.size()) merged.push_back(run2[j++]);

            outSrc.write(reinterpret_cast<const char*>(merged.data()), merged.size() * sizeof(T));
        }

        in1.close(); in2.close(); outSrc.close();
    }
}