#ifndef VECTOR_OPS_H
#define VECTOR_OPS_H

#include <vector>
#include <string>

double cosineSimilarity(const std::vector<double>& a, const std::vector<double>& b);
double cosineDistance(const std::vector<double>& a, const std::vector<double>& b);
std::vector<std::vector<double>> readVectorsFromFile(const std::string& filename);

#endif