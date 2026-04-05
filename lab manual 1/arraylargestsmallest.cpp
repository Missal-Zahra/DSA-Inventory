#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {8, 2, 5, 2, 9, 9, 1};
    int n = 7;

    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for(int i = 0; i < n; i++) {

        // largest & second largest
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }

        // smallest & second smallest
        if(arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    printf("Largest: %d\n", largest);
    printf("Second Largest: %d\n", secondLargest);
    printf("Smallest: %d\n", smallest);
    printf("Second Smallest: %d\n", secondSmallest);

    return 0;
}