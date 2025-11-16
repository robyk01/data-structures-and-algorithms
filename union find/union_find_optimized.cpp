#include <iostream>
using namespace std;

/*
    Initialize element i as a separate set by making it a root
*/
void singleton(int parent[], int i){
    parent[i] = -1;
}

/*
    Follows parent pointer until reaching the root.
    Applies path compression by making all nodes on the path point directly to the root.
    Returns the root of the tree
*/
int find(int parent[], int i){

    // climbs to the root
    int temp = i;
    while (parent[temp] >= 0){
        temp = parent[temp];
    }
    int root = temp;

    // path compression
    temp = i;
    while (parent[temp] >= 0){
        int next = parent[temp];
        parent[temp] = root;
        temp = next;
    }

    return root;
}

/*
    Finds the roots of i and j and unites the subtrees by size.
    We attach the smaller tree under the larger one
*/
void unite(int parent[], int i, int j){
    int ri = find(parent, i);
    int rj = find(parent, j);

    if (ri != rj){
        if (parent[ri] > parent[rj]){
            parent[rj] += parent[ri];
            parent[ri] = rj;
        } else {
            parent[ri] += parent[rj];
            parent[rj] = ri;
        }
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