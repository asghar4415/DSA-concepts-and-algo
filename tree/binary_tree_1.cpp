#include <iostream>

using namespace std;

class node {
    public:
    int data;
     node* left;
     node* right;

     node(int d)
     {
        this->data= d;
        this->left= NULL;
        this->right= NULL;

     }
};
node* buildtree(node* root)
{
    int data;
    cout<< "Enter the data: ";
    cin>>data;
    root= new node(data);

    if(data== -1)
    {
        return NULL;
    }
    cout<<"Enter data for left of "<<root->data<<endl;
    root->left= buildtree(root->left);
    cout<<"Enter data for the right of "<<root->data<<endl;
    root-> right= buildtree(root->right);
    return root;
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node* root= NULL;
    root= buildtree(root);
    cout<<"The tree built is: ";
    inorder(root);

    
}