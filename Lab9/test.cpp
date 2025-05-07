#include "LinkedList.h"
#include <cassert>
#include <iostream>

void test_build_and_traverse() {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    std::cout << "\n[TEST] SERVER_printLinkedList\n";
    list.SERVER_printLinkedList();
    std::cout << "\n[TEST] CLIENT_printLinkedList\n";
    list.CLIENT_printLinkedList();
}

void test_deletion_behavior() {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.SERVER_deleteCircularLinkedList();
    std::cout << "\n[TEST] CLIENT_printLinkedList after delete\n";
    list.CLIENT_printLinkedList();  // Should not segfault
}

int main() {
    std::cout << "[RUNNING UNIT TESTS]\n";
    test_build_and_traverse();
    test_deletion_behavior();
    std::cout << "\n[ALL TESTS PASSED — manually inspect output above]\n";
    return 0;
}