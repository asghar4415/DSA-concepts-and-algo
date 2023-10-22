#include <iostream>

//queue stores a list of items in which an item can be inserted at one and and removed from the other end. 
//The queue is called a First-In-First-Out (FIFO) data structure.
//operations in queue:
//1. enqueue: add an item to the queue. If the queue is full, then it is said to be an Overflow condition.
//2. dequeue: remove an item from the queue. The items are popped in the same order in which they are pushed.
//3. peek(): get the front item from the queue.
//4. isEmpty(): check if the queue is empty.

using namespace std;

//using array implementation

#define n 20

class queue{

    int* arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){
        if(back == n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back] = x;

        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front == -1 || front > back){
            cout<<"No elements in queue"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front > back){
            cout<<"No elements in queue"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.empty()<<endl;

    return 0;
}
