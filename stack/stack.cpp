#include <iostream>
#include <cstring>
using namespace std;

int st[1001], vf = 0;

/*
    Push a character onto the stack
*/
void push(int x){
    st[vf++] = x;
}

/* 
    Pop the top element from the stack if it's not empty
*/
void pop(){
    if (vf){
        vf--;
    }
}

/*
    Print the top element of the stack
*/
void top(){
    if (vf){
        cout << st[vf - 1] << endl;
    }
}

int main(){
    int n;
    cin >> n, cin.get();

    while (n){
        char op[11];
        int nr;
        cin >> op;
        if (!strcmp(op, "push")) cin >> nr, cin.get(), push(nr);
        else if (!strcmp(op, "pop")) pop();
        else top();

        n--;
    }
}