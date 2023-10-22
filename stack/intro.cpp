#include <iostream>

using namespace std;

// stack is linear data structure which stores a list of items in which an item can be added or removed from the list only at one end. It works on the LIFO(last in first out) principle.
// operations in stack:
// 1. push: adds an item in the stack. If the stack is full, then it is said to be an overflow condition.
// 2. pop: removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an underflow condition.
// 3. peek: returns top element of stack.
// 4. isEmpty: returns true if stack is empty, else false.

// implementation of stack using array

#define MAX 1000

class stack
{

    int top;

public:
    stack()
    {
        top = -1;
    }
    int a[MAX];
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
bool stack::push(int x)
{
    if (top >= -1)
    {
        top++;
        a[top] = x;
    }
    else
    {
        cout << "stack overflow" << endl;
        return -1;
    }
}
int stack::pop()
{
    if (top > -1)
    {
        top--;
        return a[top];
    }
    else
    {
        cout << "stack underflow" << endl;
        return -1;
    }
}
int stack::peek()
{
    if (top > -1)
    {

        return a[top];
    }
    else
    {
        cout << "no element in stack" << endl;
        return -1;
    }
}
bool stack::isEmpty()
{
    if (top == -1)
    {
        return -1;
    }
}

int main()
{
    stack st;
    st.push(4);
    st.push(6);
    st.push(2);
    st.push(1);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.peek();
    cout << st.isEmpty();
}