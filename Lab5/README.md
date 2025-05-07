# CSE3150_Lab5 - Cos Distance

This lab reads vectors of doubles from **`vectors.txt`** and computes cosine distances between all pairs and prints them sorted from closest to furthest.


## Description (from class pdf)
Write a C++ program that reads in vectors of doubles in Rk where 𝑘 ≥ 2 is an integer. All vectors in a file are the same size. Compute all pairwise cosine distances for all pairs of vectors. Output pairs of vectors – ordered by the cosine closeness of the vectors. The closest vectors are listed first.

See the accompanying slide deck for more information.

We can use any of our work in class.

## How to Run
1. Compile main program **`g++ -std=c++17 main.cpp vector_ops.cpp -o cos_distance`**
2. Compile unit tests **`g++ -std=c++17 test_vector_ops.cpp vector_ops.cpp -o test_vector_ops`**
3. Run main program **`./cos_distance`**
4. Run unit tests **`./test_vector_ops`**