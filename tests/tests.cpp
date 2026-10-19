#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bubble_sort.h"
#include "optimized_bubble_sort.h"
#include "insertion_sort.h"
#include "binary_insertion_sort.h"
#include "selection_sort.h"
#include "exchange_sort.h"
#include "shaker_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "natural_merge_sort.h"
#include "one_phase_merge_sort.h"
#include "two_phase_merge_sort.h"
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>

template <typename T>
void write_to_file(const std::string& filename, const std::vector<T>& data) {
    std::ofstream out(filename, std::ios::binary);
    if (!data.empty()) {
        out.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(T));
    }
}

template <typename T>
std::vector<T> read_from_file(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary | std::ios::ate);
    if (!in) return {};
    std::streamsize bytes = in.tellg();
    in.seekg(0, std::ios::beg);
    std::vector<T> data(bytes / sizeof(T));
    if (!data.empty()) {
        in.read(reinterpret_cast<char*>(data.data()), bytes);
    }
    return data;
}

TEST_CASE("Internal Sorts - Empty Array", "[internal_sort][empty]") {
    std::vector<int> empty_int = {};
    std::vector<int> expected_int = {};

    bubble_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    optimized_bubble_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    insertion_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    binary_insertion_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    selection_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    exchange_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    shaker_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    shell_sort(empty_int);
    REQUIRE(empty_int == expected_int);

    empty_int = {};
    quick_sort(empty_int);
    REQUIRE(empty_int == expected_int);
}

TEST_CASE("Internal Sorts - Single Element", "[internal_sort][single]") {
    std::vector<int> single_int = { 42 };
    std::vector<int> expected_int = { 42 };

    bubble_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    optimized_bubble_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    insertion_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    binary_insertion_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    selection_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    exchange_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    shaker_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    shell_sort(single_int);
    REQUIRE(single_int == expected_int);

    single_int = { 42 };
    quick_sort(single_int);
    REQUIRE(single_int == expected_int);
}

TEST_CASE("Internal Sorts - Already Sorted", "[internal_sort][sorted]") {
    std::vector<int> sorted_int = { 1, 2, 3, 4, 5 };
    std::vector<int> expected_int = { 1, 2, 3, 4, 5 };

    bubble_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    optimized_bubble_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    insertion_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    binary_insertion_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    selection_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    exchange_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    shaker_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    shell_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);

    sorted_int = { 1, 2, 3, 4, 5 };
    quick_sort(sorted_int);
    REQUIRE(sorted_int == expected_int);
}

TEST_CASE("Internal Sorts - Reverse Sorted", "[internal_sort][reverse]") {
    std::vector<int> reverse_int = { 5, 4, 3, 2, 1 };
    std::vector<int> expected_int = { 1, 2, 3, 4, 5 };

    bubble_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    optimized_bubble_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    insertion_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    binary_insertion_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    selection_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    exchange_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    shaker_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    shell_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);

    reverse_int = { 5, 4, 3, 2, 1 };
    quick_sort(reverse_int);
    REQUIRE(reverse_int == expected_int);
}

TEST_CASE("Internal Sorts - Identical Elements", "[internal_sort][identical]") {
    std::vector<int> identical_int = { 7, 7, 7, 7, 7 };
    std::vector<int> expected_int = { 7, 7, 7, 7, 7 };

    bubble_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    optimized_bubble_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    insertion_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    binary_insertion_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    selection_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    exchange_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    shaker_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    shell_sort(identical_int);
    REQUIRE(identical_int == expected_int);

    identical_int = { 7, 7, 7, 7, 7 };
    quick_sort(identical_int);
    REQUIRE(identical_int == expected_int);
}

TEST_CASE("Internal Sorts - Mixed Values", "[internal_sort][mixed]") {
    std::vector<int> mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    std::vector<int> expected_int = { -5, -3, -1, 0, 2, 3, 4 };

    bubble_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    optimized_bubble_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    insertion_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    binary_insertion_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    selection_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    exchange_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    shaker_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    shell_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);

    mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    quick_sort(mixed_int);
    REQUIRE(mixed_int == expected_int);
}

TEST_CASE("External Sorts - Empty File", "[external_sort][empty]") {
    std::vector<int> empty_int = {};
    std::vector<int> expected_int = {};

    std::string filename_two = "test_empty_two.bin";
    std::string filename_one = "test_empty_one.bin";
    std::string filename_nat = "test_empty_nat.bin";

    write_to_file(filename_two, empty_int);
    write_to_file(filename_one, empty_int);
    write_to_file(filename_nat, empty_int);

    two_phase_merge_sort<int>(filename_two, 2);
    one_phase_merge_sort<int>(filename_one);
    natural_merge_sort<int>(filename_nat);

    REQUIRE(read_from_file<int>(filename_two) == expected_int);
    REQUIRE(read_from_file<int>(filename_one) == expected_int);
    REQUIRE(read_from_file<int>(filename_nat) == expected_int);

    std::remove(filename_two.c_str());
    std::remove(filename_one.c_str());
    std::remove(filename_nat.c_str());
}

TEST_CASE("External Sorts - Single Element", "[external_sort][single]") {
    std::vector<int> single_int = { 42 };
    std::vector<int> expected_int = { 42 };

    std::string filename_two = "test_single_two.bin";
    std::string filename_one = "test_single_one.bin";
    std::string filename_nat = "test_single_nat.bin";

    write_to_file(filename_two, single_int);
    write_to_file(filename_one, single_int);
    write_to_file(filename_nat, single_int);

    two_phase_merge_sort<int>(filename_two, 2);
    one_phase_merge_sort<int>(filename_one);
    natural_merge_sort<int>(filename_nat);

    REQUIRE(read_from_file<int>(filename_two) == expected_int);
    REQUIRE(read_from_file<int>(filename_one) == expected_int);
    REQUIRE(read_from_file<int>(filename_nat) == expected_int);

    std::remove(filename_two.c_str());
    std::remove(filename_one.c_str());
    std::remove(filename_nat.c_str());
}

TEST_CASE("External Sorts - Already Sorted", "[external_sort][sorted]") {
    std::vector<int> sorted_int = { 1, 2, 3, 4, 5 };
    std::vector<int> expected_int = { 1, 2, 3, 4, 5 };

    std::string filename_two = "test_sorted_two.bin";
    std::string filename_one = "test_sorted_one.bin";
    std::string filename_nat = "test_sorted_nat.bin";

    write_to_file(filename_two, sorted_int);
    write_to_file(filename_one, sorted_int);
    write_to_file(filename_nat, sorted_int);

    two_phase_merge_sort<int>(filename_two, 2);
    one_phase_merge_sort<int>(filename_one);
    natural_merge_sort<int>(filename_nat);

    REQUIRE(read_from_file<int>(filename_two) == expected_int);
    REQUIRE(read_from_file<int>(filename_one) == expected_int);
    REQUIRE(read_from_file<int>(filename_nat) == expected_int);

    std::remove(filename_two.c_str());
    std::remove(filename_one.c_str());
    std::remove(filename_nat.c_str());
}

TEST_CASE("External Sorts - Reverse Sorted", "[external_sort][reverse]") {
    std::vector<int> reverse_int = { 5, 4, 3, 2, 1 };
    std::vector<int> expected_int = { 1, 2, 3, 4, 5 };

    std::string filename_two = "test_reverse_two.bin";
    std::string filename_one = "test_reverse_one.bin";
    std::string filename_nat = "test_reverse_nat.bin";

    write_to_file(filename_two, reverse_int);
    write_to_file(filename_one, reverse_int);
    write_to_file(filename_nat, reverse_int);

    two_phase_merge_sort<int>(filename_two, 2);
    one_phase_merge_sort<int>(filename_one);
    natural_merge_sort<int>(filename_nat);

    REQUIRE(read_from_file<int>(filename_two) == expected_int);
    REQUIRE(read_from_file<int>(filename_one) == expected_int);
    REQUIRE(read_from_file<int>(filename_nat) == expected_int);

    std::remove(filename_two.c_str());
    std::remove(filename_one.c_str());
    std::remove(filename_nat.c_str());
}

TEST_CASE("External Sorts - Identical Elements", "[external_sort][identical]") {
    std::vector<int> identical_int = { 7, 7, 7, 7, 7 };
    std::vector<int> expected_int = { 7, 7, 7, 7, 7 };

    std::string filename_two = "test_identical_two.bin";
    std::string filename_one = "test_identical_one.bin";
    std::string filename_nat = "test_identical_nat.bin";

    write_to_file(filename_two, identical_int);
    write_to_file(filename_one, identical_int);
    write_to_file(filename_nat, identical_int);

    two_phase_merge_sort<int>(filename_two, 2);
    one_phase_merge_sort<int>(filename_one);
    natural_merge_sort<int>(filename_nat);

    REQUIRE(read_from_file<int>(filename_two) == expected_int);
    REQUIRE(read_from_file<int>(filename_one) == expected_int);
    REQUIRE(read_from_file<int>(filename_nat) == expected_int);

    std::remove(filename_two.c_str());
    std::remove(filename_one.c_str());
    std::remove(filename_nat.c_str());
}

TEST_CASE("External Sorts - Mixed Values", "[external_sort][mixed]") {
    std::vector<int> mixed_int = { -5, 3, 0, -1, 4, 2, -3 };
    std::vector<int> expected_int = { -5, -3, -1, 0, 2, 3, 4 };

    std::string filename_two = "test_mixed_two.bin";
    std::string filename_one = "test_mixed_one.bin";
    std::string filename_nat = "test_mixed_nat.bin";

    write_to_file(filename_two, mixed_int);
    write_to_file(filename_one, mixed_int);
    write_to_file(filename_nat, mixed_int);

    two_phase_merge_sort<int>(filename_two, 2);
    one_phase_merge_sort<int>(filename_one);
    natural_merge_sort<int>(filename_nat);

    REQUIRE(read_from_file<int>(filename_two) == expected_int);
    REQUIRE(read_from_file<int>(filename_one) == expected_int);
    REQUIRE(read_from_file<int>(filename_nat) == expected_int);

    std::remove(filename_two.c_str());
    std::remove(filename_one.c_str());
    std::remove(filename_nat.c_str());
}

TEST_CASE("Internal Sorts - Double Values", "[internal_sort][double]") {
    std::vector<double> mixed_double = { 3.14, -1.5, 0.0, 2.71, -9.99, 4.2 };
    std::vector<double> expected_double = { -9.99, -1.5, 0.0, 2.71, 3.14, 4.2 };

    std::vector<double> test_vec;

    test_vec = mixed_double; bubble_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; optimized_bubble_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; insertion_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; binary_insertion_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; selection_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; exchange_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; shaker_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; shell_sort(test_vec); REQUIRE(test_vec == expected_double);

    test_vec = mixed_double; quick_sort(test_vec); REQUIRE(test_vec == expected_double);
}

TEST_CASE("External Sorts - Double Values", "[external_sort][double]") {
    std::vector<double> mixed_double = { 3.14, -1.5, 0.0, 2.71, -9.99, 4.2 };
    std::vector<double> expected_double = { -9.99, -1.5, 0.0, 2.71, 3.14, 4.2 };

    std::string filename_two = "test_double_two.bin";
    std::string filename_one = "test_double_one.bin";
    std::string filename_nat = "test_double_nat.bin";

    write_to_file(filename_two, mixed_double);
    write_to_file(filename_one, mixed_double);
    write_to_file(filename_nat, mixed_double);

    two_phase_merge_sort<double>(filename_two, 2);
    one_phase_merge_sort<double>(filename_one);
    natural_merge_sort<double>(filename_nat);

    REQUIRE(read_from_file<double>(filename_two) == expected_double);
    REQUIRE(read_from_file<double>(filename_one) == expected_double);
    REQUIRE(read_from_file<double>(filename_nat) == expected_double);

    std::remove(filename_two.c_str());
    std::remove(filename_one.c_str());
    std::remove(filename_nat.c_str());
}