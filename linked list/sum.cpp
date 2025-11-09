#include <iostream>
using namespace std;

struct node{
    int info;
    node *next = 0;
};

struct list{
    node *head = 0;
};

/*
    Insert at the end of the list
*/
void insert(node* &p, int x){
    node *last = new node();
    last->info = x;
    last->next = nullptr;

    if (!p){
        p = last;
    } else {
        node *curr = p;
        while (curr->next){
            curr = curr->next;
        }
        curr->next = last;
    }
}

/*
    Returns the sum of nodes values.
*/
int sum(node *p){
    node *prev = p;
   	node *curr = p->next;
    node *next = p->next->next;
    int sum = 0;
        
    while (next){
        if (prev->info % 2 == 0 && next->info % 2 == 0 && curr->info % 2 != 0){
        	sum += curr->info;
        }
        prev = prev->next, curr = curr->next, next = next->next;
    }
    
    return sum;
}

int main(){
    list l;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        insert(l.head, x);
    }

    cout << sum(l.head);
    return 0;
}