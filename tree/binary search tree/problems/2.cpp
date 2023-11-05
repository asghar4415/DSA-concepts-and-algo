#include <iostream>
#include <queue>

using namespace std;

//check whether given tree is BST.

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// inserting nodes in BST
node *insertnode(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertnode(root->right, data);
    }
    else
    {
        root->left = insertnode(root->left, data);
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
int minimumval(node *root)
{
    node *temp = root;

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int maxval(node *root)
{
    node *temp = root;

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
bool checkBST(node *root, int min, int max)
{
    if(root == NULL)
    {
        return 1;
    }
    if(root->data>=min && root->data<=max)
    {
        bool left= checkBST(root->left,min, root->data);
        bool right= checkBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        return 0;
    }
}

int main()
{
    node *root = NULL;
    cout << "Enter data: ";
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertnode(root, data);
        cin >> data;
    }
    levelordertraverse(root);
    int min = minimumval(root);
    int max = maxval(root);
    if (checkBST(root, min, max))
    {
        cout << "The given tree is BST." << endl;
    }
    else
    {
        cout << "The given tree is not BST." << endl;
    }
}