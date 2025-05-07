#include "bigint_fractions.h"

BigFraction sumFractions(const BigFraction& a, const BigFraction& b) {
    // Compute numerator = (*a.first * *b.second) + (*b.first * *a.second)
    // Compute denominator = *a.second * *b.second
    bigint numerator = (*a.first) * (*b.second) + (*b.first) * (*a.second);
    bigint denominator = (*a.second) * (*b.second);
    return { new bigint(numerator), new bigint(denominator) };
}

BigFraction productFractions(const BigFraction& a, const BigFraction& b) {
    bigint numerator = (*a.first) * (*b.first);
    bigint denominator = (*a.second) * (*b.second);
    return { new bigint(numerator), new bigint(denominator) };
}
