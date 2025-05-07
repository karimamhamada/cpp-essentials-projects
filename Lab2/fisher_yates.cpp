#include <iostream>
#include <cstdlib>
#include "fisher_yates.h"

using namespace std;

void print_array(int array[], int len) {
    for (int i = 0; i < len; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//swap function
int swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
    return 0;
}

//Fisher-Yates Shuffle Algorithm
void fisherYatesShuffle(int array[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(&array[i], &array[j]);
    }
}

//check if sequence is well-balanced
bool is_well_balanced(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
        if (sum < 0) return false;  // More closing parentheses than opening
    }
    return sum == 0;
}

//check if a sequence has more closings than openings throughout
bool hasMoreClosingsThanOpenings(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
        if (sum < 0) return true;
    }
    return false;
}

//check if a sequence has more openings than closings (but it should not)
bool hasMoreOpeningsThanClosings(int array[], int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum > 0;
}