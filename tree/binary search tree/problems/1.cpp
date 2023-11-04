#include <iostream>
#include <queue>

using namespace std;

//finding minimum and maximum nodes in BST

class node
{
public:
    int data;
    node* left;
    node* right;

node(int val)
{
    data= val;
    left= right= NULL;
}

};
//inserting nodes in BST
node* insertnode(node* root, int data)
{
    if(root== NULL)
    {
        root= new node(data);
        return root;
    }
    if(data>root->data)
    {
        root->right= insertnode(root->right, data);
    }
    else
    {
        root->left= insertnode(root->left, data);
    }
    return root;
}


void levelordertraverse(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) // previous level is traversed
        {
            cout << endl;
            if (!q.empty()) // queue still has some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int minvalue(node* root)
{
    node* temp= root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}


int maxvalue(node* root)
{
    node* temp= root;

    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
int main()
{
    node* root= NULL;
    cout<<"Enter data: ";
    int data;
    cin>>data;
    while(data!= -1)
    {
        root= insertnode(root, data);
        cin>>data;
    }
    levelordertraverse(root);
    cout<<"The minimum node in the tree is: " <<minvalue(root)<<endl;
    cout<<"The maximum node in the tree is: " <<maxvalue(root)<<endl;

}