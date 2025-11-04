#include <iostream>
using namespace std;

char st[1001];
int vf = 0;

void push(int x){
    st[vf++] = x;
}

void pop(){
    if (vf){
        vf--;
    }
}

void top(){
    if (vf){
        cout << st[vf - 1] << endl;
    }
}

int main(){
    int n;
    cin >> n, cin.get();
    while (n){
        char p[256];
        cin >> p;
        for (int i = 0; i < strlen(p); i++){
            push(p[i]);
        }

        int ok = 0;
        while (vf){
            if (st[vf - 1] == ')') ok++;
            else ok--;

            pop();
        }

        if (!ok) cout << 1 << endl;
            else cout << 0 << endl;
        n--;
    }
}