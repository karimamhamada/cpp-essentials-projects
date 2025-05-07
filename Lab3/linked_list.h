#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;
    node* next;
    node(int dataValue) : data(dataValue), next(nullptr) {} 
};

node* build_new_linked_list(int num_elements);
void print_linked_list(node* head);
void delete_entire_linked_list(node* &head);
int get_linked_list_data_item_value(node* head, int index);
void delete_list_element(node* &head, int index);

#endif