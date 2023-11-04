#include <iostream>
#include <queue>

using namespace std;

//searching in BST
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
static int count1= 0;
void searchinBST(node* root, int val)
{
    if(root == NULL)
    {
        cout<<val<<" not found in the tree"<<endl;
        return;
    }
    if(root->data==val)
    {
        cout<<val<<" found in the tree at level: "<<count1<<endl;
        return;
    }
    if(val > root->data)
    {
        count1++;
        searchinBST(root->right, val);
    }
    else
    {
        count1++;   
        searchinBST(root->left, val);

    }

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
    cout<<"Enter data to search: ";
    int val;
    cin>>val;
    searchinBST(root,val );
}