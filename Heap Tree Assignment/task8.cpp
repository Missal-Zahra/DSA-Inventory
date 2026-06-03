#include<iostream>
using namespace std;

bool isHeap(int arr[],int n)
{
    for(int i=0;i<=(n-2)/2;i++)
    {
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && arr[i]<arr[left])
            return false;

        if(right<n && arr[i]<arr[right])
            return false;
    }

    return true;
}

int main()
{
    int arr[]={100,80,90,30,40,50,60};

    if(isHeap(arr,7))
        cout<<"Valid Heap";
    else
        cout<<"Not Heap";
}