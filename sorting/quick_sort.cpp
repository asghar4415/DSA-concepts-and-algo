#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m= l+(r-l)/2;
        int p= arr[m];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (arr[j] < p)
            {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, r);

        int pivot = i + 1;

        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int main()
{
    int arr[8] = {5, 6, 2, -2, 6, 10, 12, 15};
    quickSort(arr, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}