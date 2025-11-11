#include <iostream>
using namespace std;

struct Queue {
    int items[101];
    int front;
    int back;
    int size;
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