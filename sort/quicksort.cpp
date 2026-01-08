#include <iostream>
using namespace std;

int partition(int a[], int p, int q) {
    int x = a[p]; // first element is the pivot
    int i = p + 1;
    int j = q;

    while (i <= j) {
        while (i <= q && a[i] <= x) i++;

        while (j >= p && a[j] > x) j--;

        if (i < j) {
            swap(a[i], a[j]); 
        }
    }
    
    swap(a[p], a[j]);
    return j; // return the fixed pivot
}

void quickSort(int a[], int p, int q) {
    if (p < q) {
        int k = partition(a, p, q);
        
        // we recursively sort the 2 arrays
        quickSort(a, p, k - 1);
        quickSort(a, k + 1, q);
    }
}