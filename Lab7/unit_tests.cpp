// unit_tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bigint_fractions.h"

// Test fraction addition using doctest
TEST_CASE("Fraction Addition") {
    // Construct test fractions using dynamic allocation.
    BigFraction f1(new bigint("2"), new bigint("3"));
    BigFraction f2(new bigint("3"), new bigint("4"));

    // Expected calculation:
    //  (2/3) + (3/4) = (2*4 + 3*3) / (3*4) = (8 + 9)/12 = 17/12
    BigFraction sum = sumFractions(f1, f2);
    CHECK(*sum.first == bigint("17"));
    CHECK(*sum.second == bigint("12"));

    // Clean up dynamically allocated memory.
    delete f1.first;  delete f1.second;
    delete f2.first;  delete f2.second;
    delete sum.first; delete sum.second;
}

// Test fraction multiplication using doctest
TEST_CASE("Fraction Multiplication") {
    // Construct test fractions using dynamic allocation.
    BigFraction f1(new bigint("2"), new bigint("3"));
    BigFraction f2(new bigint("3"), new bigint("4"));

    // Expected calculation:
    //  (2/3) * (3/4) = (2*3) / (3*4) = 6/12
    BigFraction prod = productFractions(f1, f2);
    CHECK(*prod.first == bigint("6"));
    CHECK(*prod.second == bigint("12"));

    // Clean up dynamically allocated memory.
    delete f1.first;  delete f1.second;
    delete f2.first;  delete f2.second;
    delete prod.first; delete prod.second;
}
