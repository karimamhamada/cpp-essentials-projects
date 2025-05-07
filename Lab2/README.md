# CSE3150_Lab2  

The file **`fisher_yates.cpp`** contains the main logic and functions for the Fisher-Yates shuffle and validation.

## Description (from class pdf)
In this lab we are building randomly generated well balanced lists of symbols. For example, parentheses are useful examples of well-balanced lists of matching symbols.
Here are four examples of well-balanced list of parentheses.

() <br />
()() <br />
(((()))) <br />
( () ((())) ) <br />

Given an integer 𝑛, our goal is to generate random lists of 2𝑛 matching symbols, such as parentheses.

Consider the next steps:
1. Given a list of 2𝑛 integers, fill the first 𝑛 elements with 1 and the next 𝑛 elements with -1.
2. Use the Fisher-Yates algorithm to randomly scramble this list
3. Toss out any scrambled lists that do not have non-negative or non-positive prefix sums
4. Count the number of non-negative and non-positive prefix sums and compare these with the total number of +1,-1 randomly generated sequences.

Now we need to compute the proportion of randomly permuted arrays of 1s and -1s that are validated
to be well-balanced lists. This may be best done by running many instances of the above four steps and counting which sequence of +1, -1 lists represent well-balanced lists and which ones do not.

You must run your algorithm at least several thousand times or until the proportion of well-balanced
lists seems to converge.

## How to Run
1. Compile using **`g++ -o fisher_yates main.cpp fisher_yates.cpp`**
2. Run using **`./fisher_yates`**
3. You will be prompted to enter the number of open-parenthesis, and then the program will run the trials, shuffle the arrays, and display the final results.