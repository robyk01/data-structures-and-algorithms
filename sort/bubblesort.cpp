#include <iostream>
using namespace std;

void bubblesort(int a[], int n){
    int last = n - 1;
    while (last > 0){
        int n1 = last - 1, ultim = 0;
        for (int i = 0; i < n1; i++){
            if (a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
                last = i;
            }
        }
    }
}