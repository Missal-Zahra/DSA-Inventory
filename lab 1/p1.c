#include<stdio.h>

int main()
{
    int x;
    int arr[] = {10,20,30};
    int *p =arr;
    printf("%d" , *(p+1));
    return 0;
} 