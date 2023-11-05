#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Merging two BST

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
vector<int> inorder(node* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    vector<int> left = inorder(root->left);
    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->data);
    vector<int> right = inorder(root->right);
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
node* mergeBST(node* root1, node* root2)
{
    vector <int> r2= inorder(root2);

     for (int i = 0; i < r2.size(); i++) {
           root1= insertnode(root1, r2[i]);

    }

return root1;

}

int main()
{
    node *root1 = NULL;
    node* root2 = NULL;
    cout << "Enter data for 1st tree: ";
    int data;
    cin >> data;
    while (data != -1)
    {
        root1 = insertnode(root1, data);
        cin >> data;
    }
    levelordertraverse(root1);
    
    cout << "Enter data for 2nd tree: ";
    data;
    cin >> data;
    while (data != -1)
    {
        root2 = insertnode(root2, data);
        cin >> data;
    }
    levelordertraverse(root2);

   node* merged= mergeBST(root1, root2);
   cout<<"After merging the two trees: "<<endl;
   levelordertraverse(merged);
}