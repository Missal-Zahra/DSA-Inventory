#include <iostream>
using namespace std;

int binarySearch(int arr[], int item, int low, int high)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(item == arr[mid])
            return mid + 1;

        else if(item > arr[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return low;
}

void binaryInsertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        int loc = binarySearch(arr, key, 0, j);

        while(j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {8, 4, 1, 9, 3};
    int n = 5;

    binaryInsertionSort(arr, n);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}