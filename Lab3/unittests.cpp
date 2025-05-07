#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "linked_list.h"
#include "doctest.h"

TEST_CASE("Testing build_new_linked_list and print_linked_list") {
    //make a list with 5 elements
    node* list = build_new_linked_list(5);  

    //check values at different indices
    CHECK(get_linked_list_data_item_value(list, 0) == 0);
    CHECK(get_linked_list_data_item_value(list, 1) == 1);
    CHECK(get_linked_list_data_item_value(list, 2) == 2);
    CHECK(get_linked_list_data_item_value(list, 3) == 3);
    CHECK(get_linked_list_data_item_value(list, 4) == 4);
    CHECK(get_linked_list_data_item_value(list, 10) == -1);  //out of bounds

    print_linked_list(list);          //optional print statement
    delete_entire_linked_list(list);  //delete the entire list
}

TEST_CASE("Testing delete_list_element") {
    node* list = build_new_linked_list(5);

    delete_list_element(list, 2);                           //delete element at index 2
    CHECK(get_linked_list_data_item_value(list, 2) == 3);   //new element at index 2 should be 3
    CHECK(get_linked_list_data_item_value(list, 1) == 1);   //prev element at index 1 should stay the same
    delete_entire_linked_list(list);                        //clean 
}