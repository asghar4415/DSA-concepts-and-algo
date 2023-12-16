#include <iostream>
#include <queue>

using namespace std;

// Priority queue is a type of queue in which every element has a priority and elements are dequeued according to the priority.
// in heap we can only delete the root node, but in priority queue we can delete any node.

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    int size = n - 1;
    while (size >= 0)
    {
        swap(arr[size], arr[0]);
        size--;

        heapify(arr, size, 0);
    }
}

int main()
{

    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(1);

    cout << endl;
    cout<<"Priority queue: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }


    // Min heap using priority queue

    priority_queue<int, vector<int>, greater<int>> pq1;

    pq1.push(4);
    pq1.push(2);
    pq1.push(5);
    pq1.push(1);

    cout << endl;
    cout<<"Min heap: ";
    while (!pq1.empty())
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }

    // Max heap using priority queue

    priority_queue<int, vector<int>, less<int>> pq2;

    pq2.push(4);
    pq2.push(2);
    pq2.push(5);
    pq2.push(1);

    cout << endl;
    cout<<"Max heap: ";
    while (!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    
}