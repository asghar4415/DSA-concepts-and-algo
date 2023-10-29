#include <iostream>

using namespace std;

//building tree from postorder and inorder

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

int search(int inorder[], int start, int end, int curr)
{
    for(int i= start; i<=end; i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;  
}

node* buildTree(int postorder[], int inorder[], int start, int end)
{
    static int idx= end;
    
    if (start > end)
    {
        return NULL;
    }
    int curr= postorder[idx];
    idx--;

    node* n= new node(curr);
    if(start==end)
    {
        return n;
    }
    int pos= search(inorder, start, end, curr);
    n->right= buildTree(postorder, inorder, pos+1, end);
    n->left= buildTree(postorder, inorder, start, pos-1);
    return n;
}

void inorderPrint(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    int n= sizeof(postorder)/sizeof(int);

    node* root= buildTree(postorder, inorder, 0, n-1);
    inorderPrint(root);



}