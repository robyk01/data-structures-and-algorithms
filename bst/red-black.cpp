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

// Properties
// 1. Each node is either red or black
// 2. The root of the tree is always black
// 3. Red nodes cannot have red children (no red consecutives)
// 4. Every path from a black node to its descendant leaves must contain the same number of black nodes

void insertion(node * n){
    // TODO
    // Involves a two-step process: standard BST insertion + fixing coloring violation
}

void deletion(node * n){
    // TODO
    // Involves a two-step process: standard BST deletion + fixing coloring violation
}

void search(node * n){
    // TODO
    // 1. Start at the root
    // 2.1 If the target value is equal to the current node, return the node
    // 2.2 If the target value is less than the current node, move to the left child
    // 2.3 If the target value is greater than the current node, move to the right child
    // 3. Repeat this process until the node is found or it doesn't exist
}
