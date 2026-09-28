#include <vector>
#include "quick_sort.h"
#include <catch.hpp>

TEST_CASE("quick_sorting", "[sort9]") {
    std::vector<int> v1 = { 5, 1, 7, 3, 9, 4 };
    quick_sort(v1);
    REQUIRE(v1 == std::vector<int>{1, 3, 4, 5, 7, 9});

    std::vector<int> v2 = { 42 };
    quick_sort(v2);
    REQUIRE(v2 == std::vector<int>{42});

    std::vector<int> v3 = {};
    quick_sort(v3);
    REQUIRE(v3 == std::vector<int>{});
}