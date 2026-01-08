#include <iostream>
using namespace std;

void selectionsort(int a[], int n){
    for (int i = n - 1; i > 0; i--){
        int imax = i;
        for (int j = i - 1; j >= 0; j--){
            if (a[j] > a[imax]){
                imax = j;
            }
        }
        if (imax != i){
            swap(a[imax], a[i]);
        }
    }
}