#include <iostream>
#include <math.h>

using namespace std;

// heap using array

class heap
{
    public:
    int arr[100];
    int size=0;

    void insert(int val)
    {
        size++;
        int index= size;

        arr[index]=val;

        while(index>1 && arr[index]>arr[index/2])
        {
            swap(arr[index],arr[index/2]);
            index=index/2;
        }


    }

    // when deleting the root node, we swap the root node with the last node, then we heapify the tree

    void deletionatroot()
    {
        if(size==0)
        {
            cout<<"heap is empty"<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        int index=1;
        while(index < size)
        {
            int leftindex= 2*index;
            int rightindex= 2*index+1;

            if(leftindex < size && arr[index]<arr[leftindex])
            {
                swap(arr[index],arr[leftindex]);
                index= leftindex;
            }
            else if(rightindex < size && arr[index]<arr[rightindex])
            {
                swap(arr[index],arr[rightindex]);
                index= rightindex;
            }
            else{
                return ;
            }

        }

    }


    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);

    h.print();
    h.deletionatroot();
    h.print();
}