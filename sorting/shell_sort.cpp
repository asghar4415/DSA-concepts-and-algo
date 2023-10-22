#include <iostream> 

using namespace std;

//Shell sort is used to sort an array by comparing the elements at a certain gap.
//The gap is initialized to the size of the array and is reduced by a factor of 2 in each iteration.
//The algorithm terminates when the gap becomes 1.
//The algorithm is similar to insertion sort but is more efficient than insertion sort.
// The shrink factor can be changed to 1.3 or 1.5 to improve the efficiency of the algorithm.


int main()
{
    int arr[] = {6,8,9,7,3,4,5,2,3,4,5,6,1,2,3,4,5,6,7,8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int gap = n;

    for(int i=0;gap!=0;i++)
    {
        for(int j=0;j<n-gap;j++)
        {
            if(arr[j]>arr[j+gap])
            {
                swap(arr[j],arr[j+gap]);
            }

        }
        gap=gap/1.5;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


}