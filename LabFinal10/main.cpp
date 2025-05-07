#include <iostream>
#include <thread>
#include <chrono>
#include "TimedSharedPtr.hpp"

using namespace std;
struct Node {
    int data;
    Node(int d) : data(d) {}
};

int main() {
    TimedSharedPtr<Node> myNode(new Node(7), 100); // expires in 100ms
    TimedSharedPtr<Node> myOtherNode = myNode;
    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "myNode.get() address: <" << myNode.get() << ">\n";
    cout << "myNode.use_count(): " << myNode.use_count() << endl;
    cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << endl;
    this_thread::sleep_for(chrono::milliseconds(25));
    cout << "myNode.get() address after 75ms: <" << myNode.get() << ">\n";
    this_thread::sleep_for(chrono::milliseconds(75));
    cout << "Expected Expiry\n";
    cout << "myNode.get() address after 150ms: <" << myNode.get() << ">\n";
    cout << "-----------\n";
    TimedSharedPtr<int> p(new int(42));
    cout << p.get() << endl;
    cout << "p.use_count(): " << p.use_count() << endl;
    TimedSharedPtr<int> q = p;
    cout << "p.use_count(): " << p.use_count() << endl;
    cout << "q.use_count(): " << q.use_count() << endl;
    return 0;
}