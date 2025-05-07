# CSE3150_Lab9 – Node cycles and weak_ptrs

## Description (from class pdf)
#### The purpose of this lab is to
- Leverage C++ weak_ptrs to build large, linked lists and verify their disposition
behavior.

You might create a LinkedList class that leverages a Node. But you will want to add a weak_ptr into the next Node:
```
struct Node {
 string name;
 Node(string name) : name{name} {}
 shared_ptr<Node> next; //Not weak!

 ~Node() { cout << "Node [" << name << "] destructor" << endl; }
};
```
The idea is to have a SERVER that creates the shared linked list and a CLIENT that accesses the circular linked list – unless the SERVER has deleted it.

Starter code for your LinkedList class:
```
vector<string> names = { "zero", "one", "two", "three", "four", "five"}
numberOfNodes = names.size();
shared_ptr<Node> root = make_shared<Node>(names[0]);
shared_ptr<Node> node = root;
for (int i=1; i < numberOfNodes; i++) {
    node->next = make_shared<Node>(names[i]);
    node = node->next;
}
node->next = root;
```
In my LinkedList class I have the following methods:
```
void SERVER_buildCircularLinkedList() { ... }
void SERVER_deleteCircularLinkedList() { ... }
void SERVER_printLinkedList() { ... }
void CLIENT_printLinkedList() { ... }```
```
The idea is to run these functions based on these sequential steps:
1. The SERVER creates a circular linked list using shared_ptr and weak_ptrs;
2. The SERVER prints the circular linked list by traversing the shared_ptrs.
3. The CLIENT prints the circular linked list by traversing the weak_ptrs.
4. The SERVER deletes the circular linked list via the shared_ptrs
5. The CLIENT tries to print the circular linked list, but for each weak_ptr the CLIENT finds there is no associated shared_ptr.

Here is some example output from this ordering (nothing shown for step 1):

### Server (step 2): 
```
[zero] : use_count: 3 address: 0x5793ecaeef90 next (from shared_ptr): 0x5793ecaeeff0
[one] : use_count: 2 address: 0x5793ecaeeff0 next (from shared_ptr): 0x5793ecaef050
[two] : use_count: 2 address: 0x5793ecaef050 next (from shared_ptr): 0x5793ecaef0b0
[three] : use_count: 2 address: 0x5793ecaef0b0 next (from shared_ptr): 0x5793ecaef110
[four] : use_count: 2 address: 0x5793ecaef110 next (from shared_ptr): 0x5793ecaef170
[five] : use_count: 2 address: 0x5793ecaef170 next (from shared_ptr): 0x5793ecaeef90
```

### Client (step 3):
```
[zero] : use_count: 3 address: 0x5793ecaeef90 next (from weak_ptr): 0x5793ecaeeff0
[one] : use_count: 2 address: 0x5793ecaeeff0 next (from weak_ptr): 0x5793ecaef050
[two] : use_count: 2 address: 0x5793ecaef050 next (from weak_ptr): 0x5793ecaef0b0
[three] : use_count: 2 address: 0x5793ecaef0b0 next (from weak_ptr): 0x5793ecaef110
[four] : use_count: 2 address: 0x5793ecaef110 next (from weak_ptr): 0x5793ecaef170
[five] : use_count: 2 address: 0x5793ecaef170 next (from weak_ptr): 0x5793ecaeef90
```
### Server is deleting the shared_ptrs (step 4):
```
Node [one] destructor
Node [two] destructor
Node [three] destructor
Node [four] destructor
Node [five] destructor
```
### Client after linked list deleted (step 5):
```
[zero] : use_count: 2 address: 0x5793ecaeef90 next (from weak_ptr): 0
Yipes! shared_ptr not available
Yipes! shared_ptr not available
Yipes! shared_ptr not available
Yipes! r shared_ptr not available
Yipes! shared_ptr not available
Node [zero] destructor
``` 
- Note: Node [zero] is allocated in the constructor of my LinkedList. I could check that the weak_ptr is 0 and suppress the first output.
- Alternatively we can ensure the root is deleted and check for that:

### Client after linked list deleted (step 5 alternatively):
```
Client after linked list deleted:
---------------------------------
[Nothing]
```

## How to run 
1. Compile main program
```g++ -std=c++17 main.cpp LinkedList.cpp -o weak_ptr_demo```
2. Run main program ```./weak_ptr_demo```
3. Compile unit tests ```g++ -std=c++17 test.cpp LinkedList.cpp -o test_linkedlist```
4. Run unittests ```./test_linkedlist```