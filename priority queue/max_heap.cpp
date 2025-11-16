#include <iostream>
using namespace std;

struct PriorityQueue{
    int *data;
    int size;
    int capacity;
};

PriorityQueue* createPQ(int maxCapacity){
    PriorityQueue* pq = new PriorityQueue();
    pq->size = 0;
    pq->capacity = maxCapacity;
    pq->data = new int[maxCapacity];
    return pq;
}

void insertNode(PriorityQueue* pq, int key){
    if (pq->size == pq->capacity) return;

    pq->size += 1;
    pq->data[pq->size - 1] = key;
    
    int j = pq->size - 1;
    bool heap = false;
    while (j > 0 && !heap){
        int k = (j - 1) / 2;
        if (pq->data[j] > pq->data[k]){
            swap(pq->data[j], pq->data[k]);
            j = k;
        } else {
            heap = true;
        }
    }
}

void deleteNode(PriorityQueue* pq){
    if (pq->size == 0) return;

    pq->data[0] = pq->data[pq->size - 1];
    pq->size -= 1;

    int j = 0;
    bool heap = false;
    while (2 * j + 1 < pq->size && !heap){
        int k = 2 * j + 1;
        if (k < pq->size - 1 && pq->data[k] < pq->data[k + 1])
            k++;
        if (pq->data[j] < pq->data[k]){
            swap(pq->data[j], pq->data[k]);
            j = k;
        } else {
            heap = true;
        }
    }
}

int maxElement(PriorityQueue* pq){
    if (pq->size == 0) return -1;
    return pq->data[0];
}

int main(){
    PriorityQueue* myHeap = createPQ(15); 

    insertNode(myHeap, 7);
    insertNode(myHeap, 1);
    insertNode(myHeap, 12);
    insertNode(myHeap, 9);
    insertNode(myHeap, 8);
    insertNode(myHeap, 3);
    insertNode(myHeap, 4);
    insertNode(myHeap, 5);
    insertNode(myHeap, 2);

    for(int i = 0; i < myHeap->size; i++) {
        cout << myHeap->data[i] << " ";
    }
    cout << endl;

    cout << maxElement(myHeap) << endl;

    deleteNode(myHeap);

    cout << maxElement(myHeap) << endl;

    for(int i = 0; i < myHeap->size; i++) {
        cout << myHeap->data[i] << " ";
    }
}