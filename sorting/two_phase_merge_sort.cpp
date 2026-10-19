#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

template <typename T>
void two_phase_merge_sort(const std::string& inputFile, size_t ramBlockSize) {
    std::string temp1 = "temp1.bin";
    std::string temp2 = "temp2.bin";

    {
        std::ifstream in(inputFile, std::ios::binary);
        std::ofstream out(temp1, std::ios::binary);

        std::vector<T> buffer(ramBlockSize);
        while (in) {
            in.read(reinterpret_cast<char*>(buffer.data()), ramBlockSize * sizeof(T));
            size_t bytesRead = in.gcount() / sizeof(T);
            if (bytesRead == 0) break;

            for (size_t i = 1; i < bytesRead; ++i) {
                T key = buffer[i];
                size_t j = i;
                while (j > 0 && buffer[j - 1] > key) {
                    buffer[j] = buffer[j - 1];
                    --j;
                }
                buffer[j] = key;
            }
            out.write(reinterpret_cast<const char*>(buffer.data()), bytesRead * sizeof(T));
        }
    }

    size_t totalElements = 0;
    {
        std::ifstream counter(temp1, std::ios::binary | std::ios::ate);
        if (counter) totalElements = counter.tellg() / sizeof(T);
    }
    if (totalElements <= 1) {
        if (totalElements == 1) { std::remove(inputFile.c_str()); std::rename(temp1.c_str(), inputFile.c_str()); }
        else { std::remove(temp1.c_str()); }
        return;
    }

    size_t k = ramBlockSize;
    std::string src = temp1;
    std::string dst = temp2;

    while (k < totalElements) {
        std::ifstream inSrc(src, std::ios::binary);
        std::ofstream outDst(dst, std::ios::binary);

        while (inSrc) {
            std::vector<T> run1(k), run2(k);

            inSrc.read(reinterpret_cast<char*>(run1.data()), k * sizeof(T));
            size_t size1 = inSrc.gcount() / sizeof(T);
            run1.resize(size1);

            inSrc.read(reinterpret_cast<char*>(run2.data()), k * sizeof(T));
            size_t size2 = inSrc.gcount() / sizeof(T);
            run2.resize(size2);

            if (size1 == 0) break;
            if (size2 == 0) {
                outDst.write(reinterpret_cast<const char*>(run1.data()), size1 * sizeof(T));
                break;
            }

            std::vector<T> merged;
            merged.reserve(size1 + size2);
            size_t i = 0, j = 0;
            while (i < size1 && j < size2) {
                if (run1[i] <= run2[j]) merged.push_back(run1[i++]);
                else merged.push_back(run2[j++]);
            }
            while (i < size1) merged.push_back(run1[i++]);
            while (j < size2) merged.push_back(run2[j++]);

            outDst.write(reinterpret_cast<const char*>(merged.data()), merged.size() * sizeof(T));
        }

        inSrc.close(); outDst.close();

        std::string tmp = src; src = dst; dst = tmp;
        k *= 2;
    }

    if (src == temp1) {
        std::remove(inputFile.c_str());
        std::rename(temp1.c_str(), inputFile.c_str());
        std::remove(temp2.c_str());
    }
    else {
        std::remove(inputFile.c_str());
        std::rename(temp2.c_str(), inputFile.c_str());
        std::remove(temp1.c_str());
    }
}
template void two_phase_merge_sort<int>(const std::string&, size_t);
template void two_phase_merge_sort<double>(const std::string&, size_t);
