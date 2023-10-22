#include <iostream>
#include <string>



using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }

};

// inserting elements at the end of list
void addTotail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        n->next = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

// inserting elements at the beginning of the list
void addTohead(node *&head, int val)
{
    node *n = new node(val);
    if(head == NULL)
    {
        head = n;
        n->next = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;

}

// inserting elements at random positions
void addToposition(node *&head, int val, int index)
{
    node *n = new node(val);
    node *temp = head;
    int i = 1;
    while (i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    n->next = temp->next;
    temp->next = n;
}

// deleting elements from the list
void deletion(node* &head, int val){
    node* temp = head; 
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}


// displaying the list
void display(node *head)
{
    node *temp = head;

    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<endl;
}



int main()
{
    
    node *head = NULL;

    // inserting elements at the end of the list
    addTotail(head, 3);
    addTotail(head, 7);
    addTotail(head, 9);
    addTotail(head, 1);
    display(head);

    // inserting elements at the beginning of the list
    addTohead(head, 2);
    addTohead(head, 4);
    display(head);

    // inserting elements at random positions
    addToposition(head, 5, 3);
    display(head);

    //deleting elements from the list
    deletion(head, 9);
    display(head);

    delete head;


    return 0;
}