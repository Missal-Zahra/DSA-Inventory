#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void pop() {
    if (top >= 0)
        top--;
}

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void nextGreaterElement(int arr[], int n) {
    int result[n];

    for (int i = n - 1; i >= 0; i--) {

        while (!isEmpty() && peek() <= arr[i])
            pop();

        if (isEmpty())
            result[i] = -1;
        else
            result[i] = peek();

        push(arr[i]);
    }

    printf("Output: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
}

int main() {
    int arr[] = {4, 5, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);

    return 0;
}