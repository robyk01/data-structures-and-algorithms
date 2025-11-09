#include <iostream>
using namespace std;

struct node{
    int info;
    node * next = 0;
};

struct list{
    node * head = 0;
    node * tail = 0;
};

/*
    Insert at the end of the list
*/
void insertAtEnd(list &l, int x) {
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
    Returns the head of merged lists.
*/
node * merge(list & l1, list & l2){
    if (l1.head == nullptr) return l2.head;
    if (l2.head == nullptr) return l1.head;

    node * temp = new node();
    node * merged = temp;

    node * curr1 = l1.head;
    node * curr2 = l2.head;

    while (curr1 && curr2){
        if (curr1->info < curr2->info){
            merged->next = curr1;
            curr1 = curr1->next;
        } else {
            merged->next = curr2;
            curr2 = curr2->next;
        }
        merged = merged->next;
    }

    if (curr1 != nullptr){
        merged->next = curr1;
    } else merged->next = curr2;

    return temp->next;
}

/*
    Print the nodes in the list.
*/
void print(node * n) {
    while(n) {
        cout << n->info << " ";
        n = n->next;
    }
}

int main(){
    list l1, l2;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        insertAtEnd(l1, x);
    }

    for (int i = 0; i < n; i++){
        cin >> x;
        insertAtEnd(l2, x);
    }

    print(merge(l1, l2));

    return 0;
}