#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

template <typename T>
void onePhaseSimpleMergeSort(const std::string& inputFile) {
    std::string t1 = "t1.bin", t2 = "t2.bin", t3 = "t3.bin", t4 = "t4.bin";

    size_t totalElements = 0;
    {
        std::ifstream counter(inputFile, std::ios::binary | std::ios::ate);
        if (counter) totalElements = counter.tellg() / sizeof(T);
    }
    if (totalElements <= 1) return;

    {
        std::ifstream in(inputFile, std::ios::binary);
        std::ofstream out1(t1, std::ios::binary);
        std::ofstream out2(t2, std::ios::binary);

        T val;
        bool to_first = true;
        while (in.read(reinterpret_cast<char*>(&val), sizeof(T))) {
            if (to_first) out1.write(reinterpret_cast<const char*>(&val), sizeof(T));
            else out2.write(reinterpret_cast<const char*>(&val), sizeof(T));
            to_first = !to_first;
        }
    }

    size_t k = 1;
    std::string src1 = t1, src2 = t2;
    std::string dst1 = t3, dst2 = t4;

    while (true) {
        std::ifstream in1(src1, std::ios::binary);
        std::ifstream in2(src2, std::ios::binary);
        std::ofstream out1(dst1, std::ios::binary);
        std::ofstream out2(dst2, std::ios::binary);

        int totalRunsWritten = 0;
        bool writeToFirst = true;

        while (in1 || in2) {
            std::vector<T> run1, run2;
            T val;

            size_t cnt = 0;
            while (cnt < k && in1.read(reinterpret_cast<char*>(&val), sizeof(T))) { run1.push_back(val); cnt++; }

            cnt = 0;
            while (cnt < k && in2.read(reinterpret_cast<char*>(&val), sizeof(T))) { run2.push_back(val); cnt++; }

            if (run1.empty() && run2.empty()) break;

            std::vector<T> merged;
            merged.reserve(run1.size() + run2.size());
            size_t i = 0, j = 0;
            while (i < run1.size() && j < run2.size()) {
                if (run1[i] <= run2[j]) merged.push_back(run1[i++]);
                else merged.push_back(run2[j++]);
            }
            while (i < run1.size()) merged.push_back(run1[i++]);
            while (j < run2.size()) merged.push_back(run2[j++]);

            if (writeToFirst) out1.write(reinterpret_cast<const char*>(merged.data()), merged.size() * sizeof(T));
            else out2.write(reinterpret_cast<const char*>(merged.data()), merged.size() * sizeof(T));

            totalRunsWritten++;
            writeToFirst = !writeToFirst;
        }

        in1.close(); in2.close(); out1.close(); out2.close();

        if (totalRunsWritten <= 1) break;

        std::string tmp;
        tmp = src1; src1 = dst1; dst1 = tmp;
        tmp = src2; src2 = dst2; dst2 = tmp;

        k *= 2;
    }

    std::string finalFile = (src1 == t1 || src1 == t2) ? src1 : src2;
    std::ifstream check1(src1, std::ios::binary | std::ios::ate);
    std::ifstream check2(src2, std::ios::binary | std::ios::ate);
    if (check1 && (check1.tellg() / sizeof(T)) == totalElements) finalFile = src1;
    else finalFile = src2;

    std::remove(inputFile.c_str());
    std::rename(finalFile.c_str(), inputFile.c_str());

    std::string temps[4] = { t1, t2, t3, t4 };
    for (int i = 0; i < 4; ++i) if (temps[i] != inputFile) std::remove(temps[i].c_str());
}

template void onePhaseSimpleMergeSort<int>(const std::string&);
template void onePhaseSimpleMergeSort<double>(const std::string&);