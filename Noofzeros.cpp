#include<iostream>
using namespace std;
int zeros(int arr[],int n)
{
    int low=0,high=n-1;
    int mid;
    int firstzero=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==0)
        {
            firstzero=mid;
            high=mid-1;
            
        }
        else
        {
            low=mid+1;
        }
    }
    if(firstzero==-1)
    {
        return 0;
    }
    return n-firstzero;
}
int main()
{   int arr[]={1,1,1,0,0,0};
    int n=6;
    cout<<"The no of zeros"<<zeros(arr,n);
    return 0;
}