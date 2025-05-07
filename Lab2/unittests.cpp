#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"
#include <vector>
#include <algorithm>

//helper function to compare arrays (order does not matter)
bool sameElements(const int* a, int aLen, const int* b, int bLen) {
    if (aLen != bLen) return false;
    std::vector<int> aVec(a, a + aLen);
    std::vector<int> bVec(b, b + bLen);
    std::sort(aVec.begin(), aVec.end());
    std::sort(bVec.begin(), bVec.end());
    return aVec == bVec;
}

TEST_CASE("Fisher-Yates Shuffle") {
    int array[5] = {1, 2, 3, 4, 5};
    int originalArray[5] = {1, 2, 3, 4, 5};
    
    fisherYatesShuffle(array, 5);

    CHECK(sameElements(array, 5, originalArray, 5) == true);
}

TEST_CASE("Swap Function") {
    int first = 5, second = 10;
    swap(&first, &second);
    CHECK(first == 10);
    CHECK(second == 5);
}

TEST_CASE("Well-Balanced and Imbalance Checks") {
    int balancedArray[] = {1, -1, 1, -1};
    int unBalancedArray[] = {1, 1, -1, -1, -1};

    CHECK(is_well_balanced(balancedArray, 4) == true);
    CHECK(is_well_balanced(unBalancedArray, 5) == false);
}