#include <iostream>
using namespace std;

#define MAX 5

struct Queue{
    int items[MAX];
    int front;
    int back;
    int size;
};

/*
    Initialize queue
*/
void initQueue(Queue &q){
    q.front = q.back = -1;
    q.size = 0;
}

/*
    Returns 1 if queue is empty, 0 otherwise
*/
bool isEmpty(Queue &q){
    return q.size == 0;
}

/*
    Returns 1 if queue is full, 0 otherwise
*/
bool isFull(Queue &q){
    return q.size == MAX;
}

/*
    Adds an element to the front of the queue
*/
void enqueue(Queue &q, int value){
    if (isFull(q)) return;
    if (isEmpty(q)) q.front = 0;
    q.back = (q.back + 1) % MAX;
    q.items[q.back] = value;
    q.size++;
}

/*
    Removes an element from the back of the queue
*/
void dequeue(Queue &q){
    if (isEmpty(q)) return;
    q.front = (q.front + 1) % MAX;
    q.size--;
}

/*
    Returns the first element of the queue
*/
int frontElement(Queue &q){
    return q.items[q.front];
}

/*
    Returns the last element of the queue
*/
int backElement(Queue &q){
    return q.items[q.back];
}

/*
    Prints the queue elements
*/
void print(Queue &q){
    if (isEmpty(q)) return;
    for (int i = 0; i < MAX; i++){
        cout << q.items[i] << " ";
    }
    cout << endl;
}  

int main(){
    Queue q;
    initQueue(q);

    cout << isEmpty(q) << endl;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << frontElement(q) << " " << backElement(q) << endl;

    enqueue(q, 40);
    cout << isFull(q) << endl;

    dequeue(q);

    cout << frontElement(q) << " " << backElement(q) << endl;
}