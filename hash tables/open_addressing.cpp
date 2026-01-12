#include <iostream>
using namespace std;

const int EMPTY = -1; // marker for empty slot
const int DELETED = -2; // marker for deleted slot

// hash function
int h(int k, int m){
    return k % m;
}

// lineear probing: hash with probe number i
// formula: h(k, i) = (h(k) + i) mod m
int hashWithProbe(int k, int i, int m){
    return (h(k, m) + i) % m;
}

// search for a key in the table
int search(int T[], int k, int m){
    int i = 0; // probe counter
    int j; // current slot to check

    do{
        j = hashWithProbe(k, i, m);

        if (T[j] == k){
            return j; // found the key
        }

        i = i + 1;
    }while (T[j] != EMPTY && i < m); // stop if empty or tried all slots

    return -1;
}

// insert a key into. the table
int insert(int T[], int k, int m){
    int i = 0;
    int j;

    do{
        j = hashWithProbe(k, i, m);

        if (T[j] == EMPTY || T[j] == DELETED){
            T[j] = k;
            return j;
        }

        i = i + 1;
    }while (i < m);

    return -1;
}

// delete a key from the table
bool remove(int T[], int k, int m){
    int index = search(T, k, m);

    if (index == -1){
        return false;
    }

    T[index] = DELETED;
    return true;
}