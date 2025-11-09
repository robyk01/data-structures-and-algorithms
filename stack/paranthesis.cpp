#include <iostream>
#include <cstring>
using namespace std;

char st[1001];
int vf = 0;

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

/*
    Check if a string of parentheses is balanced
*/
bool check_paranthesis(char *p){
    vf = 0;
    int len = strlen(p);
    for (int i = 0; i < len; i++){
        if (p[i] == '(') push(p[i]);
        else {
            if (vf == 0) return false;
            pop();
        }
    }

    return vf == 0;
}

int main(){
    int n;
    cin >> n, cin.get();
    while (n--){
        char p[256];
        cin >> p;
       
        if (check_paranthesis(p)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}