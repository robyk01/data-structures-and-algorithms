#include <iostream>
using namespace std;

struct Queue {
    int items[101];
    int front;
    int rear;
};

/*
    Initialize queue
*/
void initQueue(Queue &q){
    q.front = -1;
    q.rear = -1;
}

/*
    Check if queue is empty
*/
bool isEmpty(Queue q){
    return q.front == -1 || q.front > q.rear;
}

/*
    Add element to the queue
*/
void enqueue(Queue &q, int value){
    if (q.front == -1) q.front = 0;
    q.rear++;
    q.items[q.rear] = value;
}

/* 
    Remove element from the queue
*/
void dequeue(Queue &q){
    if (isEmpty(q)) return;
    q.front++;
}

/*
    Print queue elements
*/
void print(Queue q){
    if (isEmpty(q)) return;
    for (int i = q.front; i <= q.rear; i++){
        cout << q.items[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q;
    initQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    print(q);

    dequeue(q);
    print(q);
    return 0;
}