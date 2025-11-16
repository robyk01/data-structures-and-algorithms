#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};

struct tree{
    node* root;
};

/*
    Creates a new node
*/
node * createNode(int val){
    node* n = new node();
    n->val = val;
    n->left = nullptr;
    n->right = nullptr;

    return n;
}

/*
    Visits the nodes in the following order: Root -> Left child -> Right child
*/
void preorder(node* root){
    if (root == nullptr) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

/*
    Visits the nodes in the following order: Left child -> Root -> Right child
*/
void inorder(node* root){
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/*
    Visits the nodes in the following order: Left child -> Right child -> Root
*/
void postorder(node* root){
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

/*
    Inserts a node into a parent with at most 1 child
*/
void insertNode(tree &T, node* dad, int type, int val){
    node * n = createNode(val);

    if (T.root == nullptr){
        T.root = n;
        return;
    }

    if (type == -1){
        dad->left = n;
    } else if (type == 1){
        dad->right = n;
    }
}

/*
    Deletes a leaf node
*/
void deleteNode(tree &T, node* child, node* newParent){
    if (newParent->left == child) 
        newParent->left = nullptr;
    else if (newParent->right == child)
        newParent->right = nullptr;
    
    delete child;
}

int main(){
    tree * arb = new tree();
    arb->root = nullptr;

    insertNode(*arb, nullptr, 0, 10);
    insertNode(*arb, arb->root, -1, 5);
    insertNode(*arb, arb->root, 1, 20);
    insertNode(*arb, arb->root->left, -1, 3);
    insertNode(*arb, arb->root->left, 1, 7);

    preorder(arb->root);
    cout << endl;

    inorder(arb->root);
    cout << endl;

    postorder(arb->root);
    cout << endl;
}