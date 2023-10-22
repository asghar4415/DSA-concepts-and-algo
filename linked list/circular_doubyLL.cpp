#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

// inserting elements at the end of the list
void addTotail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        n->next = head;
        n->prev = head;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = head;
}

// inserting elements at the beginning of the list
void addTohead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        n->next = head;
        n->prev = head;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = head;
    head->prev = n;
    head = n;
}

// inserting elements at random positions
void addToposition(node* &head, int val, int pos){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        n->next = head;
        n->prev = head;
        return;
    }
    if(pos == 1){
        addTohead(head, val);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count != pos-1){
        temp = temp->next;
        count++;
    }
    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
}

// deleting elements from the list
void deletion(node* &head, int index){
    node* temp = head;
    int count = 1;
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        delete head;
        return;
    }
    while(count != index-1){
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete todelete;
}

// displaying the list

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}


int main()
{
    
    node *head = NULL;

    // inserting elements at the end of the list
    addTotail(head, 6);
    addTotail(head, 1);
    addTotail(head, 5);
    addTotail(head, 2);
    addTotail(head, 4);
    addTotail(head, 3);
    display(head);

    // inserting elements at the beginning of the list
    addTohead(head, 4);
    addTohead(head, 8);
    display(head);

    // inserting elements at random positions
    addToposition(head, 8, 6);
    display(head);

    //deleting elements from the list
    deletion(head, 4);
    display(head);

    delete head;


    return 0;
}