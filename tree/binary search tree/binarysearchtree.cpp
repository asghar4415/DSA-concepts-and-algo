#include <iostream>
#include <queue>

using namespace std;

// There are 3 rules for binary search tree:
// 1. Left child node is always smaller than the parent node
// 2. Right child node is always greater than the parent node
// 3. There are no duplicates in binary search tree

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
int minvalue(node *root)
{
    node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

// deleting nodes in BST
node *deletenode(node *root, int val)
{
    // basecase
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minvalue(root->right);
            root->data = min;
            root->right = deletenode(root->right, min);
            return root;
        }
    }
    else if (root->data > val)
    {

        root->left = deletenode(root->left, val);
        return root;
    }
    else
    {
        root->right = deletenode(root->right, val);
        return root;
    }
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

    //delete node
    cout<<"Enter node to delete: ";
    int val1;
    cin>>val1;
    root= deletenode(root, val1);
    cout<<"After deletion: "<<endl;
    levelordertraverse(root);
}