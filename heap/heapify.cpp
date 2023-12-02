#include <iostream>

using namespace std;

// heapify is a process of converting a binary tree into a heap data structure.
// Heapify algorithm is used to create a Max-Heap or a Min-Heap from a binary tree.
// Heapify is done in two ways:
//     -Bottom-up approach: we heapify each subtree starting from the bottom to the top.
//     -Top-down approach: we heapify each subtree starting from the top to the bottom.

// Bottom-up approach:
//     -We start heapifying the lowest level of the heap and move upwards till the root is heapified.
//     -Heapify procedure can be applied to a node only if its children nodes are heapified.
//     -So the heapification must be performed in the bottom-up order.

// Top-down approach:
//     -We start heapifying the root and move downwards till the last level of the heap is heapified.
//     -Heapify procedure can be applied to a node only if its children nodes are heapified.
//     -So the heapification must be performed in the top-down order.


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
// heapify function is used to create a heap from a binary tree. It is used in the heap sort algorithm. It is used to create a max heap or a min heap from a binary tree. 

//  Heapify is done in two ways: 

// Bottom-up approach: we heapify each subtree starting from the bottom to the top. 
// Bottom-up approach: We start heapifying the lowest level of the heap and move upwards till the root is heapified. Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom-up order.
// Top-down approach: we heapify each subtree starting from the top to the bottom. 
//  Top-down approach: We start heapifying the root and move downwards till the last level of the heap is heapified. Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the top-down order.

void heapify(int arr[], int n, int i)
{
    int largest= i;
    int left= 2*i+1;
    int right= 2*i+2;

    if(left<n && arr[left]>arr[largest])
    {
        largest= left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest= right;
    }

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }

}

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

    int arr[]={ 54, 53, 55, 52, 50};
    int n= sizeof(arr)/sizeof(arr[0]);

    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


}