#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <memory>
#include <string>

struct Node {
    std::string name;
    std::shared_ptr<Node> next;      // SERVER link
    std::weak_ptr<Node> weak_next;   // CLIENT link
    Node(const std::string& name) : name(name) {}
    ~Node() {
        std::cout << "Node [" << name << "] destructor\n";
    }
};

#endif