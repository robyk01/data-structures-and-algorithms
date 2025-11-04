#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("paranteze1.in");
ofstream fout("paranteze1.out");

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
    fin >> n, fin.get();
    while (n){
        char p[256];
        fin >> p;
       
        if (check_paranthesis(p)) fout << 1 << endl;
        else fout << 0 << endl;
        n--;
    }
}