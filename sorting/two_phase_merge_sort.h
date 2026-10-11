#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

template <typename T>
void two_phase_merge_sort(const std::string& inputFile, size_t ramBlockSize);