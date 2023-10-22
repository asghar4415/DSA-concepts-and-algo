#include <iostream>

using namespace std;

// insertion sort is a sorting algorithm that places an unsorted element at its correct position in each iteration  (considering ascending order). The algorithm maintains a sorted subarray and an unsorted subarray. In each iteration, an element from the unsorted subarray is picked and placed at the correct position in the sorted subarray. This process continues until all elements are sorted in the sorted subarray.  

int main()
{
    //use insertion sorting algorithm

    int arr[10] = { 5,1,3,6,2,9,7,4,8,10 };

    for (int i = 1; i < 10; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];


        }
        arr[j + 1] = temp;
        

    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}