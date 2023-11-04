#include <iostream>

using namespace std;

int linearsearch(int arr[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }

    }
    return -1;
}
int main()
{

    int arr[]= {3,4,56,7,8,43,2,4,5,6,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    int key;
    cin>>key;

cout<<linearsearch(arr, n, key);

}