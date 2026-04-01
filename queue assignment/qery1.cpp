#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Underflow\n";
            return;
        }

        cout << arr[front++] << " removed\n";
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
    }
};