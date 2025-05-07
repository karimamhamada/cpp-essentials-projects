#include "LinkedList.h"

int main() {
    LinkedList list;
    list.SERVER_buildCircularLinkedList();
    list.SERVER_printLinkedList();
    list.CLIENT_printLinkedList();
    list.SERVER_deleteCircularLinkedList();
    list.CLIENT_printLinkedList();
    return 0;
}
