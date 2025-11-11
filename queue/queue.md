# Queue Implementation in C++

## What is a queue?
A queue is a linear data structure that follows LIFO principle (Last In First Out) - first element to be inserted is the first to get removed.

**Example**
It works like a line in the store: customer goes to back and after it's been served leaves from the front.

##1. Queue using STL
The easiest way is to use C++ STL (Standard Template Library).

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> q;

    q.push(10); // adds element to the back of the queue
    q.push(20);
    q.push(30);

    // q = [10, 20, 30]

    q.front(); // returns the first element - 10

    q.back() // returns the last element - 30

    q.pop(); // removes element from the front

    // q = [20, 30]

}
