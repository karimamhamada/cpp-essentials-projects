#include <iostream>
#include <vector>
 
bool non_neg_prefix_sum(const std::vector<int>& lst) {
    int sum = 0;
    for (int num : lst) {
        sum += num;
        if (sum < 0) {
            return false;
        }
    }
    return true;
}
 
bool non_pos_prefix_sum(const std::vector<int>& lst) {
    int sum = 0;
    for (int num : lst) {
        sum += num;
        if (sum > 0) {
            return false;
        }
    }
    return true;
}
 
int main() {
    std::vector<int> test1 = {1, -1, 1, -1};
    std::vector<int> test2 = {1, -1, -1, 1};
    std::vector<int> test3 = {-1, 1, -1, 1};
    std::vector<int> test4 = {-1, -1, 1, 1};
 
    std::cout << "Test1 (non-neg): " << non_neg_prefix_sum(test1) << "\n";
    std::cout << "Test2 (non-neg): " << non_neg_prefix_sum(test2) << "\n";
    std::cout << "Test3 (non-pos): " << non_pos_prefix_sum(test3) << "\n";
    std::cout << "Test4 (non-pos): " << non_pos_prefix_sum(test4) << "\n";
 
    return 0;
}


//****************************************************************************
//CODE FROM CLASS ON 1/28/2025
// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "./include/doctest.h"

// //function to check if the prefix sum of an array is non-negative
// bool non_negative_prefix_sum(int myArray[], int len) {
//   bool value = true;
//   int sum = 0;
//   for (int i=0; i<len; i++){
//     sum += myArray[i];
//     if (sum < 0) {
//       value = false; 
//       break;
//     }
//   }
//   return value; 
// }

// //function to check if the prefix sum of an array is non-positive
// bool non_positive_prefix_sum(int myArray[], int len) {
//   bool value = true;
//   int sum = 0;
//   for (int i=0; i<len; i++){
//     sum += myArray[i];
//     if (sum > 0) {
//       value = false; 
//       break;
//     }
//   }
//   return value; 
// }

// //UNITTEST test case for the non_negative_prefix_sum function
// TEST_CASE("testing non_negative_prefix_sum") {
// int ary0[] = {};
// int ary1[] = {1,-1};
// int ary2[] = {-1,1};
//   //check if the prefix sum of ary0 is non-negative (should be true)
//   CHECK(non_negative_prefix_sum(ary0, sizeof(ary0)/sizeof(int)));
//   //check if the prefix sum of ary1 is non-negative (should be false)
//   CHECK_FALSE(non_negative_prefix_sum(ary1, sizeof(ary1)/sizeof(int))); #changed CHECK to CHECK_FALSE
//   //check if the prefix sum of ary2 is non-negative (should be false)
//   CHECK_FALSE(non_negative_prefix_sum(ary2, sizeof(ary2)/sizeof(int))); #changed CHECK to CHECK_FALSE
// }

// //UNITTEST test case for the non_positive_prefix_sum function
// TEST_CASE("testing non_positive_prefix_sum") {
// int ary0[] = {};
// int ary1[] = {-1,1};
// int ary2[] = {1,-1};
//   //check if the prefix sum of ary0 is non-positive (should be true)
//   CHECK(non_positive_prefix_sum(ary0, sizeof(ary0)/sizeof(int)));
//   //check if the prefix sum of ary1 is non-positive (should be false)
//   CHECK_FALSE(non_positive_prefix_sum(ary1, sizeof(ary1)/sizeof(int))); #changed CHECK to CHECK_FALSE
//   //check if the prefix sum of ary2 is non-positive (should be false)
//   CHECK_FALSE(non_positive_prefix_sum(ary2, sizeof(ary2)/sizeof(int))); #changed CHECK to CHECK_FALSE

//   cout << "Great job! The tests have passed." << endl;  //confirmation if all tests pass

// }