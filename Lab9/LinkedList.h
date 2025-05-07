#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <vector>

class LinkedList {
private:
    std::shared_ptr<Node> root;
    std::vector<std::shared_ptr<Node>> nodes;
    size_t size;

public:
    LinkedList();
    ~LinkedList() = default;

    void SERVER_buildCircularLinkedList();
    void SERVER_printLinkedList();
    void SERVER_deleteCircularLinkedList();
    void CLIENT_printLinkedList();
};

#endif
