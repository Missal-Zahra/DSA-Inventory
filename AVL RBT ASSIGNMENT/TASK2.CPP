#include <iostream>
using namespace std;

int main()
{
    int arr[] = {8, 4, 1, 9, 3};
    int n = 5;

    int comparisons = 0;
    int shifts = 0;

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }

        if(j >= 0)
            comparisons++;

        arr[j + 1] = key;
    }

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons: " << comparisons;
    cout << "\nShifts: " << shifts;

    return 0;
}