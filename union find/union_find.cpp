#include <iostream>
using namespace std;

/*
    Initialize element i as a separate set by making it a root
*/
void singleton(int parent[], int i){
    parent[i] = -1;
}

/*
    Follow parent pointer until reaching the root.
    Returns the root of the tree
*/
int find(int parent[], int i){
    int temp = i;
    while (parent[temp] >= 0){
        temp = parent[temp];
    }

    return temp;
}

/*
    Finds the roots of i and j and unites the subtrees (no union by rank/size)
*/
void unite(int parent[], int i, int j){
    int ri = find(parent, i);
    int rj = find(parent, j);

    if (ri != rj){
        parent[rj] = ri;
    }
}

int main(){
    int parent[10];

    for (int i = 0; i < 10; i++) {
        singleton(parent, i);
    }

    unite(parent, 1, 2);
    unite(parent, 2, 3);
    unite(parent, 4, 5);

    for (int i = 0; i < 10; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;

    cout << find(parent, 3) << endl;  
    cout << find(parent, 5) << endl;
    cout << find(parent, 7) << endl;
}