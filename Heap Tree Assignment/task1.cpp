#include <iostream>
using namespace std;

bool MaxHeap(int arr[], int n)
{
    for(int i = 0; i <= (n-2)/2; i++)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[i] < arr[left])
            return false;

        if(right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

bool MinHeap(int arr[], int n)
{
    for(int i = 0; i <= (n-2)/2; i++)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[i] > arr[left])
            return false;

        if(right < n && arr[i] > arr[right])
            return false;
    }
    return true;
}

int main()
{
    int arr[] = {100, 80, 90, 20, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(MaxHeap(arr, n))
        cout << "Max Heap";
    else if(MinHeap(arr, n))
        cout << "Min Heap";
    else
        cout << "Not a Heap";

    return 0;
}