#include "linked_list.h"
#include <iostream>

node* build_new_linked_list(int num_elements) {
    if (num_elements <= 0) return nullptr; 
    node* root = new node(0); 
    node* current = root;

    for (int i = 1; i < num_elements; ++i) {
        current->next = new node(i);  
        current = current->next;   
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
    while (head != nullptr) {
        node* nextNode = head->next;
        head->next = nullptr;
        delete head;
        head = nextNode;
    }
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
    return -1;
}

void delete_list_element(node* &head, int index) {
    if (head == nullptr) return;

    node* current = head;
    if (index == 0) {  
        head = current->next;
        current->next = nullptr;
        delete current;
        return;
    }
    for (int i = 0; current != nullptr && i < index - 1; ++i) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        return;  
    }
    node* nextNode = current->next->next;
    current->next->next = nullptr;  
    delete current->next;
    current->next = nextNode;
}