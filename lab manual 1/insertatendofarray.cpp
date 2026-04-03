#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30};
    int n = 3, val = 40;

    arr[n] = val;
    n++;

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}