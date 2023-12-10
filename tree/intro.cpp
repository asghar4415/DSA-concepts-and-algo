#include <iostream>

using namespace std;

// binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. A recursive definition using just set theory notions is that a (non-empty) binary tree is a tuple (L, S, R), where L and R are binary trees or the empty set and S is a singleton set containing the root. Some authors allow the binary tree to be the empty set as well.

//maximum nodes at level L = 2^L
//maximum nodes in a tree of height H = 2^H - 1
//minimum possible height of a tree with N nodes = log2(N+1)
//In Binary tree where every node has 0 or 2 children, number of leaf nodes is always one more than nodes with two children.

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }

    
}; 
int main()
{
    node *root= new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);
    
    return 0;
}

