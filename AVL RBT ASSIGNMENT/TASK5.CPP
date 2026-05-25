#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 3, 4, 5, 1};
    int n = 5;

    int newn;

    do
    {
        newn = 0;

        for(int i = 1; i < n; i++)
        {
            if(arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                newn = i;
            }
        }

        n = newn;

    } while(n > 1);

    cout << "Sorted Array: ";

    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}