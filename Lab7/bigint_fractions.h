#ifndef BIGINT_FRACTIONS_H
#define BIGINT_FRACTIONS_H

#include <utility>
#include "bigint.h"

// BigFraction is defined as a pair of pointers to bigint.
using BigFraction = std::pair<bigint*, bigint*>;

// Returns the sum of two fractions:
// (a.first/a.second) + (b.first/b.second)
BigFraction sumFractions(const BigFraction& a, const BigFraction& b);

// Returns the product of two fractions:
// (a.first/a.second) * (b.first/b.second)
BigFraction productFractions(const BigFraction& a, const BigFraction& b);

#endif // BIGINT_FRACTIONS_H
