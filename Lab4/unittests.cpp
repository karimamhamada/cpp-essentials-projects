#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "linked_list.h"
#include "doctest.h"

TEST_CASE("Testing build_new_linked_list and print_linked_list") {
    node* list = build_new_linked_list(5);  

    CHECK(get_linked_list_data_item_value(list, 0) == 0);
    CHECK(get_linked_list_data_item_value(list, 1) == 1);
    CHECK(get_linked_list_data_item_value(list, 2) == 2);
    CHECK(get_linked_list_data_item_value(list, 3) == 3);
    CHECK(get_linked_list_data_item_value(list, 4) == 4);
    CHECK(get_linked_list_data_item_value(list, 10) == -1);  

    print_linked_list(list);
    delete_entire_linked_list(list);
}

TEST_CASE("Testing delete_list_element") {
    node* list = build_new_linked_list(5);

    delete_list_element(list, 2);  
    CHECK(get_linked_list_data_item_value(list, 2) == 3);  
    CHECK(get_linked_list_data_item_value(list, 1) == 1);  
    delete_entire_linked_list(list);
}

TEST_CASE("Testing move constructor") {
    node original(10);
    original.next = new node(20);

    node moved(std::move(original));

    CHECK(moved.data == 10);
    CHECK(moved.next != nullptr);
    CHECK(moved.next->data == 20);
    CHECK(original.next == nullptr);  
}

TEST_CASE("Testing move assignment operator") {
    node first(1);
    first.next = new node(2);

    node second(10);
    second = std::move(first);

    CHECK(second.data == 1);
    CHECK(second.next != nullptr);
    CHECK(second.next->data == 2);
    CHECK(first.next == nullptr);  
}