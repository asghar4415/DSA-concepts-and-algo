#include <iostream>

using namespace std;

int main()
{
    int arr[10] = { 5,1,3,6,2,9,7,4,8,10 };
    int temp;

    for (int i = 0; i < 10; i++)
    {
        for (int j = i+1; j < 10; j++)
        {
            if (arr[i] > arr[j]) //swap
            {
                temp = arr[i];
                arr[i] = arr[j ];
                arr[j] = temp;
            }

        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }


}