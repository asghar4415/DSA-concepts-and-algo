#include <iostream>

using namespace std;

//Stack implementation using linked list

class stack
{
    public:
    int data;
    stack * next;

    stack()
    {
        data=0;
        next=NULL;
    }

    void push(int data)
    {
        stack * temp= new stack();
        temp->data=data;
        temp->next=next;
        next=temp;
    }

    void pop()
    {
        if(next==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        stack * temp=next;
        next=next->next;
        delete temp;
    }

    int top()
    {
        if(next==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return next->data;
    }

    bool empty()
    {
        if(next==NULL)
        {
            return true;
        }
        return false;
    }


};

int main()
{
    stack st;
    st.push(2);
    st.push(4);
    st.push(9);
    st.push(6);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();

    cout<<st.empty()<<endl;
    st.pop();
    st.push(10);
    cout<<st.top()<<endl;
    

    return 0;
}