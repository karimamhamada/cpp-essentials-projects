#include "linked_list.h"
#include <iostream>

//functions are named after their purpose

node* build_new_linked_list(int num_elements) {
    node* root = new node(0);  //root node with data 0
    node* current = root;

    for (int i = 1; i < num_elements; ++i) {
        current->next = new node(i);  //new node with data i
        current = current->next;      //move to the next node
    }
    return root;
}

void print_linked_list(node* head) {
    node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void delete_entire_linked_list(node* &head) {
    node* current = head;
    while (current != nullptr) {
        node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;  //after deleting all nodes
}

int get_linked_list_data_item_value(node* head, int index) {
    node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return current->data;
        }
        current = current->next;
        ++count;
    }
    return -1;  //if index is out of bounds
}

void delete_list_element(node* &head, int index) {
    if (head == nullptr) return;  //if list empty, do nothing

    node* current = head;
    if (index == 0) {  //if deleting head node
        head = current->next;
        delete current;
        return;
    }

    //traverse thru to the node and stop before one to delete
    for (int i = 0; current != nullptr && i < index - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        return;  //if index out of bounds, do nothing
    }

    node* nextNode = current->next->next;
    delete current->next;
    current->next = nextNode;
}