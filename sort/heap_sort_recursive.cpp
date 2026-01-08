#include <iostream>
using namespace std;

// we search for the largest value of the sons
// swap with the parent if found

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[largest] < a[left]) largest = left;
    if (right < n && a[largest] < a[right]) largest = right;

    if (largest != i){
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}


// start forming the heap from n/2 beucase n/2 -> n - 1 are leaves
// leaves already have the heap property

void maxheap(int a[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--){
        swap(a[0],a[i]);
        heapify(a, i, 0);
    }
}