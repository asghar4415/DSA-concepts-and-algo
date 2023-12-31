#include <iostream>

using namespace std;

void merge(int *arr, int s, int m, int e)
{
    int i, j;
    int arr1_size = m - s + 1;
    int arr2_size = e - m;

    int *arr1 = new int[arr1_size];
    int *arr2 = new int[arr2_size];

    for (i = 0; i < arr1_size; i++)
    {
        arr1[i] = arr[s + i];
    }

    for (j = 0; j < arr2_size; j++)
    {
        arr2[j] = arr[m + 1 + j];
    }

    int i_arr1 = 0, i_arr2 = 0, i_main = s;

    for (; i_arr1 < arr1_size && i_arr2 < arr2_size;)
    {
        if (arr1[i_arr1] < arr2[i_arr2])
        {
            arr[i_main] = arr1[i_arr1];
            i_arr1++;
        }
        else
        {
            arr[i_main] = arr2[i_arr2];
            i_arr2++;
        }
        i_main++;
    }
    while (i_arr1 < arr1_size)
    {
        arr[i_main] = arr1[i_arr1];
        i_arr1++;
        i_main++;
    }
    while (i_arr2 < arr2_size)
    {
        arr[i_main] = arr2[i_arr2];
        i_arr2++;
        i_main++;
    }

    delete[] arr1;
    delete[] arr2;
}

void mergesort(int *arr, int s, int e)
{
    if (s < e)
    {
        int m= s + (e - s) / 2;
        mergesort(arr, s, m);
        mergesort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

int main()
{
    int arr[] = {3, 1, -1, 0, -56, 2, 7, 9, 4, 6, 1, 6, 8, 4, 5, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}