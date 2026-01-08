#include <iostream>
using namespace std;

void heapify(int a[], int n, int t){
    int j = t;
    bool heap = false;
    while (2 * j + 1 < n && !heap){
        int k = 2 * j + 1;

        if (k < n - 1 && a[k] < a[k + 1]){
            k++;
        }

        if (a[j] < a[k]){
            swap(a[j], a[k]);
            j = k;
        } else {
            heap = true;
        }
    }
}

void heapsort(int a[], int n){
    for (int i = n / 2; i >= 0; i--){
        heapify(a, n, i);
    }

    int r = n - 1;
    while (r > 0){
        swap(a[0], a[r]);
        heapify(a, r, 0);
        r--;
    }
}
