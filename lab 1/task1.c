#include <stdio.h>
int main() {
    int x = 10;
    int *p = &x;
  printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Value using pointer: %d\n", *p);
   printf("Address stored in pointer: %p\n", p);
    return 0;
}