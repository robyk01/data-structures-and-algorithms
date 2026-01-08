#include <iostream>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;
};

// returns the height of the tree
int height(node * root){
    if (!root) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

// returns the balance factor of subtrees
int balanceFactor(node * root){
    if (!root) return 0;
    return height(root->left) - height(root->right);
}

// checks if the BST is AVL (balance factor should be between -1 and 1)
bool isAVL(node * root){
    if (!root) return true;

    int bf = balanceFactor(root);
    if (bf < -1 || bf > 1) return false;

    return isAVL(root->left) && isAVL(root->right);
}


void insertion(node * n){
// TODO
// Must do one of 4 rotations: LL, RR, LR, RL
}


void deletion(node * n){
// TODO
// Must do one of 4 rotations: LL, RR, LR, RL
}


int main(){
    // Create a balanced tree
    node * root = new node{10, nullptr, nullptr};
    root->left = new node{5, nullptr, nullptr};
    root->right = new node{15, nullptr, nullptr};
    root->left->left = new node{3, nullptr, nullptr};
    root->left->right = new node{7, nullptr, nullptr};

    cout << "Tree height: " << height(root) << endl;
    cout << "Balance factor of root: " << balanceFactor(root) << endl;
    cout << "Is AVL tree? " << (isAVL(root) ? "Yes" : "No") << endl;

    // Create an unbalanced tree
    node * unbalanced = new node{10, nullptr, nullptr};
    unbalanced->left = new node{5, nullptr, nullptr};
    unbalanced->left->left = new node{3, nullptr, nullptr};
    unbalanced->left->left->left = new node{1, nullptr, nullptr};

    cout << "\nUnbalanced tree height: " << height(unbalanced) << endl;
    cout << "Balance factor of unbalanced root: " << balanceFactor(unbalanced) << endl;
    cout << "Is AVL tree? " << (isAVL(unbalanced) ? "Yes" : "No") << endl;

    return 0;
}