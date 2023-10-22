#include <iostream>

using namespace std;

// Comb sort algorithm is used to sort an array by comparing the elements at a certain gap.
// The gap is initialized to the size of the array and is reduced by a factor of 1.3 in each iteration.
// The algorithm terminates when the gap becomes 1.
// The algorithm is similar to bubble sort but is more efficient than bubble sort.

int main()
{
    int arr[] = {5, 4, 3, 2, 4, 5, 6, 2, 8, 4, 9, 1, 0, 5, 3};

    int n = sizeof(arr) / sizeof(arr[0]);
    int gap = n;

    for (int i = 0; gap != 1; i++)
    {

        gap = gap /1.3;

        for (int j = 0; j < n - gap; j++)
        {
            if (arr[j] > arr[j + gap])
            {
                swap(arr[j], arr[j + gap]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}