#include <iostream>

using namespace std;

class node
{

public:

int data;
node* next;
node* prev;

node(int d)
{
data = d;
next = NULL;    
prev = NULL;
}
};

// inserting elements at the end of list
void addTotail(node *&head, int val)
{
node *n = new node(val);
if (head == NULL)
{
head = n;
return;
}
node* temp = head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next=n;
n->prev=temp;
}

// inserting elements at the beginning of the list
void addTohead(node *&head, int val)
{
node *n = new node(val);

n->next = head;
head->prev = n;
head = n;

}

// inserting elements at random positions
void addToposition(node *&head, int val, int index)
{
    node* n= new node(val);
int i=1;
node* temp= head;

while(i<index-1)
{
    temp=temp->next;
    i++;
}
n->next=temp->next;
temp->next->prev=n;
temp->next=n;
}

//deleting elements from the list
void deletion(node* &head, int index){
    node* temp = head;
    int i=1;
    while(i<index-1){
        temp=temp->next;
        i++;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete todelete;

}


// displaying the list
void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    node *head= NULL;

    // inserting elements at the end of list
    addTotail(head, 7);
    addTotail(head, 2);
    addTotail(head, 9);
    addTotail(head, 5);
    display(head);

    // inserting elements at the beginning of the list
    addTohead(head, 3);
    addTohead(head, 9);
    display(head);

    // inserting elements at random positions
    addToposition(head, 8, 2);
    display(head);

    // deleting elements from the list using index
    deletion(head, 5);
    display(head);


    delete head;
    return 0;
}