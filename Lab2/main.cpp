#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fisher_yates.h"

using namespace std;

int random_function() { //generates a random number
    return rand();
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); 

    int n;
    cout << "Enter a number of open-parentheses: ";
    cin >> n;

    int trials = 20000;  //total # of random sequences generated
    int validSequence = 0, moreOpeningsThanClosings = 0, moreClosingsThanOpenings = 0;

    for (int attempt = 0; attempt < trials; attempt++) {
        int arrayValues[2 * n];
        for (int i = 0; i < n; i++) { //fill first 'n' elements with 1 and next 'n' elements with -1
            arrayValues[i] = 1;
            arrayValues[i + n] = -1;
        }

        fisherYatesShuffle(arrayValues, 2 * n); //shuffle array
        if (is_well_balanced(arrayValues, 2 * n)) { //check if shuffle is balanced well
            validSequence++;
        } else {
            if (hasMoreClosingsThanOpenings(arrayValues, 2 * n)) {
                moreClosingsThanOpenings++;
            } else if (hasMoreOpeningsThanClosings(arrayValues, 2 * n)) {
                moreOpeningsThanClosings++;
            }
        }
    }

    double proportionValid = static_cast<double>(validSequence) / trials;
    double proportionMoreOpenings = static_cast<double>(moreOpeningsThanClosings) / trials;
    double proportionMoreClosings = static_cast<double>(moreClosingsThanOpenings) / trials;

    //print results
    cout << "\nTotal number of sequences generated: " << trials << endl;
    cout << "Total number of well-balanced sequences: " << validSequence << endl;
    cout << "Proportion of valid sequences: " << proportionValid << endl;
    cout << "Total number of sequences where openings > closings (should be 0): " << moreOpeningsThanClosings << endl;
    cout << "Proportion of sequences with openings > closings (should be 0): " << proportionMoreOpenings << endl;
    cout << "Total sequences with where closings > openings: " << moreClosingsThanOpenings << endl;
    cout << "Proportion of sequences where closings > openings: " << proportionMoreClosings << endl;

    return 0;
}