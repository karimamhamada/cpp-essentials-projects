# CSE3150_LabFinal10 – TimedSharedPtr
## Description (from class pdf)
#### The purpose of this lab is to
- Implement a template class for TimedSharedPtr

For example:
```
template<typename T>
class TimedSharedPtr { … }
```

In addition to examples and unit tests.

The only function your **TimedSharedPtr** must check for expiry is the **get()** method. You may
do more if you wish, of course.

## Grading Criteria
You may use AI. However, you must document which AI system you use and how you use it. Anything from AI will be commensurately discounted so add value of your own for credit. 

As an example, if you choose to use mostly AI found code for **TimedSharedPtr**, then
add **TimedSharedPtr** functionality without using AI or add **TimedSharedPtr** using your
own work. Document these details.
1. Quality of your code: ¼
2. Quality of your unit tests: ¼
3. You must supply basic documentation: ¼
4. Anything that makes your implementation special: ¼ 

### Example and Details
I put an example of my ControlTimedSharedPtr in
- cse3150-exercises/week14/lab/starterFINAL.cpp at main · wonder-phil/cse3150-exercises
· GitHub
- https://github.com/wonder-phil/cse3150-exercises/blob/main/week14/lab/starterFINAL.cpp

#### Here is the body of a basic main function: 
```
TimedSharedPtr<Node> myNode(new Node(7), 100);
 // Node holds data of 7 and expires in 100 milliseconds
 // Note: the 100 is an argument to the TimedSharedPtr constructor
TimedSharedPtr<Node> myOtherNode = myNode;
this_thread::sleep_until(Clock::now() + chrono::milliseconds(50));
 // sleep for 50 milliseconds
cout << "myNode.get() address: <" << myNode.get() << ">" << endl;
cout << "myNode.use_count(): " << myNode.use_count() << endl;
cout << "myOtherNode.use_count(): " << myOtherNode.use_count() << endl;
this_thread::sleep_until(Clock::now() + chrono::milliseconds(25));
 // sleep for 25 more milliseconds
cout << "myNode.get() address: <" << myNode.get() << ">" << endl;
this_thread::sleep_until(Clock::now() + chrono::milliseconds(75));
 // sleep for 75 more milliseconds – totaling 150 milliseconds!
cout << "The ptr should have expired: " << endl;
cout << "myNode.get() address: <" << myNode.get() << ">" << endl;
cout << "-----------" << endl;
TimedSharedPtr<int> p(new int(42));
cout << p.get() << endl;
cout << "p.use_count(): " << p.use_count() << endl;
TimedSharedPtr<int> q = p;
cout << "p.use_count(): " << p.use_count() << endl;
cout << "q.use_count(): " << q.use_count() << endl;
```
#### Here is the expected output with annotations in blue 
```
ControlTimedSharedPtr 0x641840d2ceb0 start: 0 ms
myNode.get() address: <0x641840d2ceb0> // after 50 milliseconds
myNode.use_count(): 2
myOtherNode.use_count(): 2
myNode.get() address: <0x641840d2ceb0> // after 75 milliseconds
The ptr should have expired: // after 150 milliseconds
myNode.get() address: <Yeo! Expired 0>
-----------
ControlTimedSharedPtr 0x641840d2d310 start: 0 ms
0x641840d2d310
p.use_count(): 1
p.use_count(): 2
q.use_count(): 2
ControlTimedSharedPtr 0x641840d2d310 end: 0 ms // computers are very fast!
ControlTimedSharedPtr 0x641840d2ceb0 end: 150 ms
```

Note: AI was used to help with trouble shooting errors when building the code and project, but not to write the code itself. It was able to assist and decifer unknown error codes. I used the notes from class and lectures to complete this project. 

## How to run 
1. Compile main program
```g++ -std=c++17 main.cpp -o main```
2. Run main program ```./main```
3. Compile unit tests ```g++ -std=c++17 unit_tests.cpp -o tests```
4. Run unittests ```./tests```