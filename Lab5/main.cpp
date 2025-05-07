#include "vector_ops.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <tuple>

int main() {
    auto vectors = readVectorsFromFile("vectors.txt");
    std::vector<std::tuple<int, int, double>> results;

    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double dist = cosineDistance(vectors[i], vectors[j]);
            results.emplace_back(i, j, dist);
        }
    }

    std::sort(results.begin(), results.end(), [](auto& a, auto& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

//MAIN PRINT STATEMENTS
    for (const auto& [i, j, dist] : results) {
        std::cout << i << " " << j << " cos dist = " << std::fixed << std::setprecision(6) << dist << "\n";
    }

    return 0;
}