#include <iostream>

using namespace std;

// selection sort is a sorting algorithm that sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

int main()
{
    int arr[10] = { 5,1,3,6,2,9,7,4,8,10 };

    for (int i = 0; i < 10; i++)
    {
        int small_idx= i;
        for (int j = i+1; j < 10; j++)
        {
            if (arr[j] < arr[small_idx])
            {
                small_idx = j;
            }
        }
        swap(arr[i], arr[small_idx]);
      
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    



    return 0;
}