#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// inserting at head

void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

// inserting at tail

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout<<"NULL"<<endl;
}

// searching in linked list

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

// deletion at head

void deleteAthead(node* &head)
{
    node* todelete=head;
    head=head->next;

    delete todelete;
}

// deletion in linked list

void deletion(node* &head, int val)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        deleteAthead(head);
        return;
    }

    node* temp = head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;

    temp->next=temp->next->next;

    delete todelete;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAthead(head, 4);

    display(head);
    cout << endl;
    cout << search(head, 7) << endl;

deletion(head, 3);
display(head);
cout<<endl;
deleteAthead(head);
display(head);
insertAtTail(head, 3);
display(head);

    return 0;
}