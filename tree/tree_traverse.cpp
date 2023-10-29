#include <iostream>

using namespace std;

// we have 3 types of traversals
// 1. Preorder traversal
// 2. Inorder traversal
// 3. Postorder traversal

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

// Preorder traversal
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder traversal
void postorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

/* 
                      1
                    /   \
                   2     3
                  / \   / \
                 4   5 6   7

*/
    cout << "Preorder traversal: " << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: " << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: " << endl;
    postorder(root);
    cout << endl;

    return 0;
}