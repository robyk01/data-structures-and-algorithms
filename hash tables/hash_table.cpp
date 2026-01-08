#include <iostream>
using namespace std;

// Hash Table is a data structure that stores key, value pairs and supports fast operations like insert, search, delete
// Collisions:
//      Separate Chaining: each bucket stores a list (linked list) of items
//      Open Addressing: all items live in the array. If a bucket is taken, you probe for another slot



// Separate Chaining
const int M = 7;

struct Entry {
    int key;
    int value;
    Entry * next;
};

// hash function
int hashKey(int key){
    int h = key % M;
    if (h < 0) h += M;
    return h;
}

void initTable(Entry* table[]) {
    for (int i = 0; i < M; i++) table[i] = nullptr;
}

// we search for a key in the table
Entry* findEntry(Entry * table[], int key){
    int idx = hashKey(key);

    Entry * curr = table[idx];
    while (curr){
        if (curr->key == key)
            return curr;
        curr = curr->next;
    }

    return nullptr;
}

// we search for the key, if it exists, we update its value, otherwise we create a new entry
void insert(Entry * table[], int key, int value){
    int idx = hashKey(key);

    Entry * existing = findEntry(table, key);
    if (existing){
        existing->value = value;
        return;
    }

    Entry * e = new Entry{key, value, table[idx]};
    table[idx]->next = e;
    table[idx] = e;
}

// loop the table, if the key is not head, we skip the node, if its the head we just iterate to the next node
bool deleteKey(Entry * table[], int key){
    int idx = hashKey(key);

    Entry * curr = table[idx];
    Entry * prev = nullptr;

    while (curr){
        if (curr->key == key){
            if (prev) prev->next = curr->next;
            else table[idx] = curr->next;
            delete curr;
            return true;
        }

        prev = curr;
        curr = curr->next;
    }

    return false;
}

