# CSE3150_Lab4

CONTINUING LAB3
- Take the linked list from the last lab and implement the move copy constructor. Also implement the move constructor.
- Implement the move methods
- Give good unit tests showing these methods work.
- You must use the code from lab03. This code must be based on the code form the class repo.

<br /> 

---
---
---
<br /> 

# CSE3150_Lab3
The file **`linked_list.cpp`** contains the implementation for the linked list functions. 

## Description (from class pdf)
You are to extend the struct Node from Lab to include (1) a copy-constructor, and (2) a destructor.

```
struct Node {
    int data;
    struct Node * next;
};
```

Once you build unit tests validating the functions build_linked_list and print_linked_list then write
functions (with sufficient unit tests):
- delete_entire_linked_list()
- get_linked_list_data_item_value(Node * root, int node_number)
- delete_list_element (int node_number)

where **`node_number`** specifies the element to remove from the linked list.

Build unit tests and make the code have good header files – including declarations separated from
definitions.

## How to Run
1. Compile using **`g++ -std=c++11 linked_list.cpp unittests.cpp -o test -I./doctest`**
2. Run using **`./test`**