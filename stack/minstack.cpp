#include <iostream>
using namespace std;

int st[100001] = {0}, vf = 0;
int mins[100001] = {0}, vfmin = 0;

/*
    Pushes a value onto the stack.
    If the value is smaller or equal to the current minimum it is also pushed onto the min stack.
*/
void push(int val) {
    if (vfmin == 0 || mins[vfmin - 1] >= val) mins[vfmin++] = val;
    st[vf++] = val;
}

/*
    Removes the top element from the stack.
    If the removed element is equal to the current min, it is also removed from the min stack
*/
void pop() {
    if (vf){
        --vf;
        if (vfmin && st[vf] == mins[vfmin - 1]){
            --vfmin;
        }
    } else {
        return;
    }
}

/*
    Returns top element of the stack.
*/
int top() {
    if (vf == 0) return -1;
    return st[vf - 1];
}

/*
    Returns top element of the min stack.
*/
int getMin() {
    if (vfmin == 0) return -1;
    return mins[vfmin - 1];
}

int main(){
    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            push(x);
            cout << "Pushed " << x << endl;
        }
        else if (cmd == "pop") {
            pop();
            cout << "Popped top element" << endl;
        }
        else if (cmd == "top") {
            cout << "Top: " << top() << endl;
        }
        else if (cmd == "getMin") {
            cout << "Min: " << getMin() << endl;
        }
        else {
            cout << "Invalid operation!" << endl;
        }
    }
    return 0;
}