#include <iostream>
#include "bigint_fractions.h"

int main() {
    BigFraction f1(new bigint("2"), new bigint("3"));
    BigFraction f2(new bigint("3"), new bigint("4"));

    BigFraction sum = sumFractions(f1, f2);
    BigFraction prod = productFractions(f1, f2);

    std::cout << "Fraction Arithmetic Demo:" << std::endl;
    std::cout << "Sum: " << *sum.first << "/" << *sum.second << std::endl;
    std::cout << "Product: " << *prod.first << "/" << *prod.second << std::endl;

    delete f1.first; delete f1.second;
    delete f2.first; delete f2.second;
    delete sum.first; delete sum.second;
    delete prod.first; delete prod.second;

    return 0;
}
