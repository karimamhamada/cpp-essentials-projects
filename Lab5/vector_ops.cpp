#include "vector_ops.h"
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>

double cosineSimilarity(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) throw std::invalid_argument("Vector size mismatch");
    double dot = 0.0, normA = 0.0, normB = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];
        normA += a[i] * a[i];
        normB += b[i] * b[i];
    }
    if (normA == 0 || normB == 0) throw std::invalid_argument("Zero magnitude vector");
    return dot / (std::sqrt(normA) * std::sqrt(normB));
}

double cosineDistance(const std::vector<double>& a, const std::vector<double>& b) {
    double cos_sim = cosineSimilarity(a, b);
    return std::acos(std::min(1.0, std::max(-1.0, cos_sim))); // safe acos
}

std::vector<std::vector<double>> readVectorsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<double>> vectors;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::vector<double> vec;
        double val;
        while (ss >> val) vec.push_back(val);
        if (!vec.empty()) vectors.push_back(vec);
    }
    return vectors;
}