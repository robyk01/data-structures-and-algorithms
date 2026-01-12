#include <iostream>
using namespace std;

struct node {
    int val;
    int key;
};

// search for a key in the table
node * search(node * T[], int key){
    return T[key];
}


// insert a new value in the table
node * insert(node * T[], node * x){
    return T[x->key] = x;
}


// delete a value from the table
node * remove(node * T[], node * x){
    return T[x->key] = nullptr;
}