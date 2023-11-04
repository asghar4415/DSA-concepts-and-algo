#include <iostream>
#include <queue>
#include <iostream>

using namespace std;
//calcualte height of the tree

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for left of " << root->data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for the right of " << root->data << endl;
    root->right = buildtree(root->right);
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

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left= height(root->left);
    int right= height(root->right);

    int ans= max(left, right)+ 1;
    return ans;

}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    cout << "The tree built is: " << endl;
    // level order traverse
    levelordertraverse(root);

    //calculating height of the tree
    cout<<"The height of the tree is: "<<height(root);
    

}