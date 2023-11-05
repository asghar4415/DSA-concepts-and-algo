#include <iostream>
#include <math.h>

using namespace std;

class node
{
public:
   int data;
   int height;
   node *left;
   node *right;

   node(int d)
   {
      this->data = d;
      this->left = NULL;
      this->right = NULL;
      height = 1;
   }
};
int max(int a, int b)
{
   return (a > b) ? a : b;
}
int minvalue(node *root)
{
   node *temp = root;
   while (root->left != NULL)
   {
      root = root->left;
   }
   return root->data;
}
int height(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   return root->height;
}
void updateheight(node *root)
{
   if (root == NULL)
   {
      return;
   }
   int left = height(root->left);
   int right = height(root->right);

   root->height = max(left, right) + 1;
}
int balancefactor(node *root)
{
   if (root == NULL)
   {
      return 0;
   }
   return height(root->left) - height(root->right);
}
node *rotateleft(node *root)
{
   node *y = root->right;
   node *temp = y->left;

   y->left = root;
   root->right = temp;
   updateheight(root);
   updateheight(y);
   return y;
}
node *rotateright(node *root)
{
   node *x = root->left;
   node *temp = x->right;
   x->right = root;
   root->left = temp;

   updateheight(root);
   updateheight(x);

   return x;
}
node *insertnode(node *root, int data)
{
   if (root == NULL)
   {
      root = new node(data);
      return root;
   }
   if (data < root->data)
   {
      root->left = insertnode(root->left, data);
   }
   else if (data > root->data)
   {
      root->right = insertnode(root->right, data);
   }
   else
   {
      return root;
   }

   updateheight(root);
   int bal = balancefactor(root);

   if (bal > 1)
   {
      if (data < root->left->data)
      {
         return rotateright(root);
      }
      else
      {
         root->left = rotateleft(root->left);
         return rotateright(root);
      }
   }
   else if (bal < -1)
   {
      if (data > root->right->data)
      {
         return rotateleft(root);
      }
      else
      {
         root->right = rotateright(root->right);
         return rotateleft(root);
      }
   }
   return root;
}

void inorder(node *root)
{
   if (root == NULL)
   {
      return;
   }

   inorder(root->left);
   cout << root->data << " ";
   inorder(root->right);
}

node *deleteNode(node *root, int data)
{
   if (root == NULL)
   {
      return root;
   }

   if (data < root->data)
   {
      root->left = deleteNode(root->left, data);
   }
   else if (data > root->data)
   {
      root->right = deleteNode(root->right, data);
   }
   else
   {
      if (root->left == NULL && root->right == NULL)
      {
         delete root;
         return NULL;
      }
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
      else if (root->left != NULL && root->right != NULL)
      {
         int min = minvalue(root->right);
         root->data = min;
         root->right = deleteNode(root->right, min);
         return root;
      }
   }
   if (root == NULL)
   {
      return root;
   }
   updateheight(root);
   int bal = balancefactor(root);

   if (bal > 1)
   {
      if (data < root->left->data)
      {
         return rotateright(root);
      }
      else
      {
         root->left = rotateleft(root->left);
         return rotateright(root);
      }
   }
   else if (bal < -1)
   {
      if (data > root->right->data)
      {
         return rotateleft(root);
      }
      else
      {
         root->right = rotateright(root->right);
         return rotateleft(root);
      }
   }
   return root;
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
   cout << "In-Order traverse: ";
   inorder(root);
   cout << endl;

   deleteNode(root, 3);
   cout << "Tree After Deletion: ";
   inorder(root);
}
