# CSE3150_Lab7 – BigInts and Timing cost

## Description (from class pdf)
The purpose of this lab is to
1. Leverage a the C++ big int library to represent large ints and fractions.
a. To start we will learn the basics of bigints – using the STL pair container
2. Check the time-cost of large ints versus ints and long ints

We will use binints from: https://github.com/rgroshanrg/bigint

Copy and paste the bigint.h file from this website or use wget: https://raw.githubusercontent.com/rgroshanrg/bigint/refs/heads/main/Big%20Integer%20Library%20in%20Single%20file/bigint.h

We want to have each bigInt fraction as a STL pair representing the fraction of two integers. The pair first is the numerator and the pair second is the denominator.

Define the functions
1. Product of two fractions of big ints
2. Sum of two fractions of big ints

See timeTestExample.cpp in https://github.com/wonder-phil/cse3150-
exercises/tree/main/week11/lab on how to do time testing.

## How to run 
1. Compile
```g++ -std=c++17 bigint_fractions.cpp unit_tests.cpp -Wl,--allow-multiple-definition -o bigint_tests```
2. Run the program ```./bigint_lab```
3. Run unittests ```./bigint_tests```