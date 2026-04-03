#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40};
    int n = 4, pos = 2, val = 25;

    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];  // shift
    }

    arr[pos] = val;
    n++;

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}