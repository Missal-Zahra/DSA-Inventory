#include <stdio.h>

#define MAX 100
// here we're doing Deque implementation using array
int deque[MAX];
int front = -1, rear = -1;

// first Check if empty
int isEmpty() {
    return front == -1;
}

// then Add at rear
void pushBack(int x) {
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

// then Remove from front
void popFront() {
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// then Remove from back
void popBack() {
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

// then Get front element
int getFront() {
    return deque[front];
}

// then Get back element
int getBack() {
    return deque[rear];
}

void slidingWindowMax(int arr[], int n, int k) {
    front = rear = -1;

    for (int i = 0; i < n; i++) {

        // Remove indices out of window
        if (!isEmpty() && getFront() <= i - k)
            popFront();

        // Remove smaller elements
        while (!isEmpty() && arr[getBack()] < arr[i])
            popBack();

        // Add current index
        pushBack(i);

        // Print max when window is full
        if (i >= k - 1)
            printf("%d ", arr[getFront()]);
    }
}

int main() {
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    printf("Sliding Window Maximum= ");
    slidingWindowMax(arr, n, k);

    return 0;
}