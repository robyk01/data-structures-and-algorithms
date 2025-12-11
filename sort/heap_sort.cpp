#include <iostream>
using namespace std;

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (largest < n && a[largest] < a[left]) largest = left;
    if (largest < n && a[largest] < a[right]) largest = right;

    if (largest != i){
        swap(largest, i);
        heapify(a, largest, i);
    }
}

void maxheap(int a[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--){
        swap(a[0],a[i]);
        heapify(a, i, 0);
    }
}