# Queue Implementation in C++

## What is a queue?
A queue is a linear data structure that follows FIFO principle (First In First Out) - first element to be inserted is the first to get removed.

**Example**
It works like a line in the store: customer goes to back and after it's been served leaves from the front.

## 1. Queue using STL
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

    q.back(); // returns the last element - 30

    q.pop(); // removes element from the front

    // q = [20, 30]
}
```

## 2. Queue using arrays
This version shows how queues work inside. We use a struct to group the array, front and rear pointer together.

```cpp
struct Queue {
    int items[101];
    int front;
    int back;
};

/*
    Initialize queue
*/
void initQueue(Queue &q){
    q.front = -1;
    q.back = -1;
}


/*
    Check if queue is empty
*/
bool isEmpty(Queue q){
    return q.front == -1 || q.front > q.back;
}


/*
    Add element to the queue
*/
void enqueue(Queue &q, int value){
    if (q.front == -1) q.front = 0;
    q.back++;
    q.items[q.back] = value;
}


/* 
    Remove element from the queue
*/
void dequeue(Queue &q){
    if (isEmpty(q)) return;
    q.front++;
}


/*
    Returns the first element of the queue
*/
int frontElement(Queue &q){
    if (q.front == -1) return;
    return q.front;
}


/*
    Returns the last element of the queue
*/
int backElement(Queue &q){
    if (q.back == -1) return;
    return q.back;
}


/*
    Print queue elements
*/
void print(Queue &q){
    if (isEmpty(q)) return;
    for (int i = q.front; i <= q.back; i++){
        cout << q.items[i] << " ";
    }
    cout << endl;
}
```
