#include <iostream>
using namespace std;

struct node {
    int info;
    node * next = 0;
};

struct list {
    node * head = 0;
    node * tail = 0;
};

/*
    Insert a node at the beginning of the list.
*/
void insertAtHead(list &l, int x) {
    node * n = new node();
    n->info = x;

    if (l.head == nullptr){
        l.head = l.tail = n;
    } else {
        n->next = l.head;
        l.head = n;
    }
}

/*
    Insert a node at the end of the list.
*/
void insertAtTail(list &l, int x) {
    node * last = new node();
    last->info = x;
    last->next = nullptr;

    if (l.head == nullptr){
        l.head = l.tail = last;
    } else {
        l.tail->next = last;
        l.tail = last;
    }
}

/*
    Insert a node at any position of the list.
*/
void insertNode(list &l, int pos, int x) {
    node * n = new node();
    n->info = x;

    // if list is empty
    if (l.head == nullptr){
        l.head = l.tail = n;
        return;
    }

    // if inserted at head
    if (pos <= 1){
        n->next = l.head;
        l.head = n;
        return;
    }

    node * curr = l.head;
    while (pos > 2 && curr->next){
        curr = curr->next;
        pos--;
    }

    n->next = curr->next;
    curr->next = n;

    // if inserted at end
    if (n->next == nullptr){
        l.tail = n;
    }
    
}

/*
    Deletes a node from the list
*/
void deleteNode(list &l, int x) {
    // if list is empty
    if (l.head == nullptr) return;

    // if x is the head
    if (l.head->info == x){
        node * temp = l.head;
        l.head = l.head->next;
        if (l.head == nullptr) l.tail = nullptr;
        delete temp;
        return;
    }

    // if x is the tail
    if (l.tail->info == x){
        node * curr = l.head;
        while (curr->next != l.tail){
            curr = curr->next;
        }
        delete l.tail;
        l.tail = curr;
        l.tail->next = nullptr;
        return;
    }

    node * curr = l.head;
    while (curr->next && curr->next->info != x){
        curr = curr->next;
    }

    // if x not found
    if (curr->next == nullptr) return;

    node * temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

/*
    Print the nodes in the list.
*/
void print(list l) {
    node * p = l.head;

    while(p) {
        cout << p->info << " ";
        p = p->next;
    }
}

int main() {

    int n, a;
    list l;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        insertAtTail(l, a);
    }
    print(l);

}