#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5, val = 5;

    for(int i = n; i > 0; i--) {
        arr[i] = arr[i-1];  // shift right
    }

    arr[0] = val;
    n++;

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}