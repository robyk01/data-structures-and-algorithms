#include <iostream>
using namespace std;


// Each node has an array of pointers to chiildren
// and a boolean flag indicating if current node marks the end of a word
struct TrieNode {
    TrieNode * succ[3];
    bool isEndOfWord;

    TrieNode(){
        isEndOfWord = false;
        for (int i = 0; i < 3; i++){
            succ[i] = nullptr;
        }
    }
};


// search for a word/sequence in the Trie
// returns true if sequence exists and is marked as end of word, false otherwise
bool search(TrieNode * root, int a[], int m){
    TrieNode * p = root;
    int i = 0;

    while (p && i < m){
        p = p->succ[a[i]];
        i++;
    }

    return (p != nullptr && p->isEndOfWord);
}


// insert a word/sequence into the Trie
void insert(TrieNode * root, int a[], int m){
    TrieNode * p = root;

    for (int i = 0; i < m; i++){
        int digit = a[i];

        if (p->succ[digit] == nullptr){
            p->succ[digit] = new TrieNode();
        }
        p = p->succ[digit];
    }

    p->isEndOfWord = true;
}


// check if a node has any children
bool hasSuccessors(TrieNode * p){
    for (int i = 0; i < 3; i++){
        if (p->succ[i]) return true;
    }
    return false;
}


// delete a node/sequence from the Trie (recursive)
// returns a pointer to the node (or nullptr if node should be deleted)
TrieNode * remove(TrieNode * p, int a[], int m, int i){
    if (!p) return nullptr;

    if (i == m){
        p->isEndOfWord = false;

        if (!hasSuccessors(p)){
            delete p;
            return nullptr;
        }
        return p;
    }

    int digit = a[i];
    p->succ[digit] = remove(p->succ[digit], a, m, i+ 1);

    if (!hasSuccessors(p) && !p->isEndOfWord){
        delete p;
        return nullptr;
    }

    return p;
}