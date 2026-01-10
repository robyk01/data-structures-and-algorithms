#include <iostream>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;
};

// implementation
node * bst(int v[], int p, int q){
    if (p <= q){
        int m = (p + q) / 2;
        node * t = new node();
        t->val = v[m];
        t->left = bst(v, p, m - 1);
        t->right = bst(v, m + 1, q);

        return t;
    }  
}

// check if its bst using inorder traversal
// recursively check the left subtree, the current node's value should be greater than the prev value

bool inorder(node * root, int &prev){
    if (!root) return true;

    if (!inorder(root->left, prev))
        return false;

    if (root->val <= prev)
        return false;

    prev = root->val;

    return inorder(root->right, prev);
}


// check if its bst using a min and max value range
bool isBSTminmax(node * root, int min, int max){
    if (!root) return true;

    if (root->val <= min || root->val >= max)
        return false;

    bool left = isBSTminmax(root->left, min, root->val);
    bool right = isBSTminmax(root->right, root->val, max);
    return left && right;
}


// iterative search
bool search(node * root, int data){
    node * p = root;

    while (p){
        if (p->val == data) return true;
        else if (data < p->val) p = p->left;
        else p = p->right;
    }

    return false;
}


// recursive search
bool recSearch(node * root, int data){
    if (!root) return false;
    else if (root->val == data) return true;

    if (data < root->val) return recSearch(root->left, data);
    else return recSearch(root->right, data);
}


int main(){
    // Create a sorted array to build BST
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build BST from sorted array
    node * root = bst(arr, 0, n - 1);

    // Test if it's a valid BST using inorder traversal
    int prev = INT_MIN;
    cout << "Is BST: inorder check " << (inorder(root, prev) ? "Yes" : "No") << endl;

    // Test if it's a valid BST using min-max method
    cout << "Is BST: min-max check " << (isBSTminmax(root, INT_MIN, INT_MAX) ? "Yes" : "No") << endl;

    // Create an invalid BST manually
    node* invalidBST = new node{10, nullptr, nullptr};
    invalidBST->left = new node{5, nullptr, nullptr};
    invalidBST->right = new node{15, nullptr, nullptr};
    invalidBST->left->right = new node{12, nullptr, nullptr}; // Invalid: 12 > 10

    prev = INT_MIN;
    cout << "\nInvalid tree - Is BST (inorder check)? " << (inorder(invalidBST, prev) ? "Yes" : "No") << endl;
    cout << "Invalid tree - Is BST (min-max check)? " << (isBSTminmax(invalidBST, INT_MIN, INT_MAX) ? "Yes" : "No") << endl;

    return 0;
}