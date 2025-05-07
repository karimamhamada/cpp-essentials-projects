#include "LinkedList.h"

LinkedList::LinkedList() : root(nullptr), size(0) {}

void LinkedList::SERVER_buildCircularLinkedList() {
    std::vector<std::string> names = {"zero", "one", "two", "three", "four", "five"};
    size = names.size();

    root = std::make_shared<Node>(names[0]);
    nodes.push_back(root);
    std::shared_ptr<Node> current = root;

    for (size_t i = 1; i < size; ++i) {
        current->next = std::make_shared<Node>(names[i]);
        current = current->next;
        nodes.push_back(current);
    }

    current->next = root;  // Circular link

    for (size_t i = 0; i < size; ++i) {
        nodes[i]->weak_next = nodes[i]->next;
    }
}

void LinkedList::SERVER_printLinkedList() {
    std::cout << "Server (step 2):\n";
    std::shared_ptr<Node> current = root;
    for (size_t i = 0; i < size; ++i) {
        std::cout << "[" << current->name << "] : use_count: " << current.use_count()
                  << " address: " << current.get()
                  << " next (from shared_ptr): " << current->next.get() << "\n";
        current = current->next;
    }
}

void LinkedList::CLIENT_printLinkedList() {
    std::cout << "Client (step 3 or 5):\n";

    if (!root) {
        std::cout << "[Nothing] — list root is null (probably deleted)\n";
        return;
    }

    std::shared_ptr<Node> current = root;
    for (size_t i = 0; i < size && current; ++i) {
        std::cout << "[" << current->name << "] : use_count: " << current.use_count()
                  << " address: " << current.get();

        auto next_shared = current->weak_next.lock();
        if (next_shared) {
            std::cout << " next (from weak_ptr): " << next_shared.get() << "\n";
            current = next_shared;
        } else {
            std::cout << " next (from weak_ptr): 0\n";
            std::cout << "Yipes! shared_ptr not available\n";
            break;
        }
    }
}

void LinkedList::SERVER_deleteCircularLinkedList() {
    std::cout << "Server is deleting the shared_ptrs (step 4)\n";
    nodes.clear();
    root.reset();
}
