#include <stdio.h>
int main() {
    int arr[] = {10,20,30,40};
    int *p = arr;
    printf("arr[2] using pointer: %d\n", *(p+2));
    for(int i=0;i<4;i++){
        printf("%d ", *(p+i));
    }
    printf("\nAddress difference: %ld\n", &arr[1] - &arr[0]);
    return 0;
}