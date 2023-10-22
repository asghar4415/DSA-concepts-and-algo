#include <iostream>

using namespace std;


int binarysearch(int arr[], int n, int key)
{
    int s=0;
    int e=n;

    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;

}

int main()
{
int arr[]= {1,2,3,4,5,6,7,8};

int n= sizeof(arr)/sizeof(arr[0]);
 int key;
 cin>>key;

// sort(arr,n);
// cout<<"sorted array: ";
// for(int i=0;i<n;i++)
// {
//     cout<<arr[i]<<" ";
// }
cout<<endl;
cout<<binarysearch(arr, n, key);
}