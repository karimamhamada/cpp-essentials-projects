#include "vector_ops.h"
#include <cassert>
#include <iostream>
#include <cmath> 

void runTests() {
    std::vector<double> v1{1.0, 1.0, 1.0};
    std::vector<double> v2{1.0, 1.0, 0.0};

    double expected_cos_sim = 2.0 / (std::sqrt(3.0) * std::sqrt(2.0));
    double expected_angle = std::acos(expected_cos_sim);

    assert(std::abs(cosineSimilarity(v1, v2) - expected_cos_sim) < 1e-6);
    assert(std::abs(cosineDistance(v1, v2) - expected_angle) < 1e-6);

    std::cout << "PASSED!\n";
}

int main() {
    runTests();
    return 0;
}