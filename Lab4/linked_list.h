#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct node {
    int data;
    node* next;

    //default constructor
    node(int dataValue) : data(dataValue), next(nullptr) {}

    //move constructor
    node(node&& other) noexcept : data(other.data), next(other.next) {
        other.next = nullptr;
    }
    //move assignment operator
    node& operator=(node&& other) noexcept {
        if (this != &other) {
            delete next;
            data = other.data;
            next = other.next;
            other.next = nullptr; 
        }
        return *this;
    }
    //destructor
    ~node() {
        // std::cout << "Deleting node with data: " << data << std::endl;       //USED THIS TO DEBUG
        delete next;  
    }
};
node* build_new_linked_list(int num_elements);
void print_linked_list(node* head);
void delete_entire_linked_list(node* &head);
int get_linked_list_data_item_value(node* head, int index);
void delete_list_element(node* &head, int index);

#endif